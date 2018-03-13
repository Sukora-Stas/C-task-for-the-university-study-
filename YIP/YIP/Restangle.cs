using System;

namespace YIP
{
    public class Restangle : Figure2D
    {
        public int height { get; set; }
        public int width { get; set; }


        int _sum; // Переменная для хранения суммы

        public Restangle(int sum)
        {
            _sum = sum;
        }

        public int CurrentSum
        {
            get { return _sum; }
        }

        public void Put(int sum)
        {
            _sum += sum;
        }




        // Объявляем делегат
        public delegate void AccountStateHandler(string message);
        // Создаем переменную делегата
        AccountStateHandler _del;

        // Регистрируем делегат
        public void RegisterHandler(AccountStateHandler del)
        {
            _del = del;
        }

        public void Withdraw(int sum)
        {
            if (sum <= _sum)
            {
                _sum -= sum;

                if (_del != null)
                    _del($"Сумма {sum} снята со счета");
            }
            else
            {
                if (_del != null)
                    _del("Недостаточно денег на счете");
            }
        }

        public Restangle()
        {
        }

        public Restangle(int height, int width)
        {
            this.height = height;
            this.width = width;
        }

        public void draw()
        {
            
            int n =width;

            for (int j = 0; j < n; j++)
            {
                Console.Write("* ");   
            }
            
            int i = 0;
            while (i != height)
            {
                Console.WriteLine("*" + new string(' ', height) + "*");
                i++;
            }
            for (int j = 0; j < n; j++)
            {
                Console.Write("* ");   
            }
            Console.ReadLine();
            
        }

        public void move(int x1, int x2, int y1, int y2)
        {
            throw new NotImplementedException();
        }


        public void scale(int scale)
        {
        }

        public void Rotate(double radius)
        {
        }
    }
}