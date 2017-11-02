#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/shm.h>
#define write_str 1000
#define write_one_str 100
#define read_str 75

int main ()
{
    pid_t pid1,pid2;
    int i=0;
    int pipe1[2],pipe2[2];
    char str[20];
    
    struct timeval t;
    struct sembuf sem_lock1 =   { 0, -1, IPC_NOWAIT };
    struct sembuf sem_unlock1 = { 0,  1, IPC_NOWAIT };
    struct sembuf sem_lock2 =   { 1, -1, IPC_NOWAIT };
    struct sembuf sem_unlock2 = { 1,  1, IPC_NOWAIT };
    sigset_t set;
    siginfo_t info;
    key_t key;
    int sid,size;
    int *shared; /* pointer to the shm */
    int shmid;
    /* аргумент arg для системного вызова semctl */
    union semun {
        int val;                /* значение для SETVAL-а */
        struct semid_ds *buf;   /* буфер для IPC_STAT и IPC_SET */
        ushort *array;          /* массив для GETALL и SETALL */
        struct seminfo *__buf;  /* буфер для IPC_INFO */
        void *__pad;
    };
    union semun arg;
    sigaddset(&set, SIGUSR2);
    sigprocmask(SIG_SETMASK, &set, NULL);
    if(pipe(pipe1) < 0){
        /* Если создать pipe не удалось, печатаем об этом сообщение и прекращаем работу */
        printf("Can\'t create pipe\n");
        exit(-1);
    }
    if(pipe(pipe2) < 0){
        /* Если создать pipe не удалось, печатаем об этом сообщение и прекращаем работу */
        printf("Can\'t create pipe\n");
        exit(-1);
    }
    /* Создаем уникальный ключ через вызов ftok() */
    key = ftok(".",getpid());
    /* Открываем множество семафоров - не создаем! */
    if((sid = semget(key, 2, 0666|IPC_CREAT)) == -1)
    {
        printf("Semaphore set does not exist!%s\n",strerror(errno));
        exit(1);
    }
    arg.val = 1;
    semctl(sid, 0, SETVAL, arg);
    semctl(sid, 1, SETVAL, arg);
    if((shmid = shmget(IPC_PRIVATE, 2*sizeof(int), IPC_CREAT | 0666)) == -1)
    {
        printf("sh mem set does not exist!%s\n",strerror(errno));
        exit(1);
    }
    pid1 = fork ();
    if (pid1 == 0)
    { //child1
        sigwaitinfo(&set, NULL);
        //sleep(1);
        printf ("pid1=%d\n", getpid());
        shared =(int *) shmat(shmid,(void *)0, 0);
        close(pipe1[0]);
        close(pipe2[0]);
        while( (*shared+*(shared+1)) < write_str)
        {
            if(semop(sid, &sem_lock1, 1) == 0)
            {
                for(i=0;i<write_one_str ;i++)
                {
                    gettimeofday( &t, NULL );
                    sprintf(str,"%d %d %d",*shared,getpid(),t.tv_usec/1000);
                    write(pipe1[1], str , 20);
                    *shared += 1;
                }
                semop(sid, &sem_unlock1, 1);
                sleep(1);
                
            }
            if(semop(sid, &sem_lock2, 1) == 0)
            {   for(i=0;i<write_one_str ;i++)
            {
                gettimeofday( &t, NULL );
                sprintf(str,"%d %d %d",*(shared +1),getpid(),t.tv_usec/1000);
                write(pipe2[1], str , 20);
                *(shared +1) += 1;
            }
                semop(sid, &sem_unlock2, 1);
                sleep(1);
            }
            
        }
        close(pipe1[1]);
        close(pipe1[2]);
    }
    else
    {
        if (pid1 > 0)
        {
            
            pid2 = fork ();
            if (pid2 == 0)
            { //child2
                sigwaitinfo(&set, NULL);
                printf ("pid2=%d\n", getpid());
                shared =(int *) shmat(shmid, 0, 0);
                close(pipe1[0]);
                while( (*shared+*(shared+1)) < write_str)
                {
                    if(semop(sid, &sem_lock1, 1) == 0)
                    {
                        for(i=0;i<write_one_str ;i++)
                        {
                            gettimeofday( &t, NULL );
                            sprintf(str,"%d %d %d",*shared,getpid(),t.tv_usec/1000);
                            write(pipe1[1], str , 20);
                            *shared += 1;
                        }
                        semop(sid, &sem_unlock1, 1);
                        sleep(1);
                    }
                    if(semop(sid, &sem_lock2, 1) == 0)
                    {   for(i=0;i<write_one_str ;i++)
                    {
                        gettimeofday( &t, NULL );
                        sprintf(str,"%d %d %d",*(shared + 1),getpid(),t.tv_usec/1000);
                        write(pipe2[1], str , 20);
                        *(shared + 1) += 1;
                    }
                        semop(sid, &sem_unlock2, 1);
                        sleep(1);
                    }
                    
                }
                close(pipe1[1]);
                close(pipe2[1]);
            }
            else
            { //parent
                if (pid2 > 0)
                {
                    printf ("pid=%d\n", getpid());
                    close(pipe1[1]);
                    close(pipe2[1]);
                    shared =(int *) shmat(shmid,  0, 0);
                    *shared = 1;
                    *(shared + 1) = 1;
                    kill(0,SIGUSR2);
                    waitpid(pid1, NULL, 0);
                    waitpid(pid2, NULL, 0);
                    shmctl(shmid, IPC_RMID, 0);
                    printf("pipe1\n");
                    for(i=0;i<read_str;i++){
                        size = read(pipe1[0], str,20);
                        printf("%s\n",str);
                    }
                    printf("pipe2\n");
                    for(i=0;i<read_str;i++){
                        size = read(pipe2[0], str, 20);
                        printf("%s\n",str);
                    }
                    close(pipe1[0]);
                    close(pipe2[0]);
                }
                else
                    printf ("error2 fork\n");
            }
        }
        else
            printf ("error1 fork\n");
    }
}
