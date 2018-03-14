using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace YIP
{
    class Program
    {
        delegate void GetMessage();

        static void Main(string[] args)
        {
            menu();
        }

        private static void menu()
        {
            bool ex = true;
            while (ex)
            {
                Console.Clear();
                message("Hello man :) Variant 1. \nSukora and Stolpner");
                message("Please select menu item");
                message("1: Laba 1 - done"); //
                message("2: Laba 2 - done"); //
                message("3: Laba 3 - done"); //
                message("4: Laba 4 - done");
                message("5: Laba 5 - 50/50");
                message("6: Laba 6 - done");
                message("7: Laba 7 - done");
                message("8: Laba 8");
                message("9: Exit");

                int value;

                try
                {
                    value = int.Parse(read());
                }
                catch (Exception e)
                {
                    Console.WriteLine("Input corect value");
                    read();
                    continue;
                }

                switch (value)
                {
                    case 1:
                        laba1();
                        break;
                    case 2:
                        laba2();
                        break;
                    case 3:
                        laba3();
                        break;
                    case 4:
                        laba4();
                        break;
                    case 5:
                        laba5();
                        break;
                    case 6:
                        laba6();
                        break;
                    case 7:
                        break;
                    case 8:
                        break;
                    case 9:
                        message("Do you want to go out? Y/N");
                        string exit = read();
                        if (exit.ToLower().Equals("y"))
                            ex = false;
                        break;
                    default:
                        message("Correct you'r input");
                        break;
                }
            }
        }

        private static void Show_Message(GetMessage _del)
        {
            _del.Invoke();
        }


        private static void laba1()
        {
            message("Используя среду разработки Microsoft Visual Studio,\n" +
                    " создать консоль-ное приложение на языке программирования C#.\n" +
                    " Приложение должно вы-числять значение выражения (см. варианты).\n" +
                    " Ввод данных должен произво-диться с клавиатуры.");
            message("input variable");
            message("a: ", false);
            int a = int.Parse(read());

            Console.Write("b: ");
            int b = int.Parse(read());

            Console.Write("c: ");
            int c = int.Parse(read());


            double sum = 0;

            if (a == 0)
            {
                Console.WriteLine("На ноль делить нельзя");
                read();
                return;
            }

            if (b == 0)
            {
                Console.WriteLine("В отрицательную степень ноль не возводится");
                read();
                return;
            }

            sum = ((b + Math.Sqrt(Math.Pow(b, 2) + 4 * a * c)) / 2 * a) - Math.Pow(a, 3) * c + Math.Pow(b, -2);


            message("Otvet: " + sum, false);


            read();
        }

//2-502-5/502-5     //ipe
        private static void laba2()
        {
            message(
                "Построить систему классов для описания плоских геометрических фигур: круга, квадрата, прямоугольника.\n" +
                " Предусмотреть методы для создания объ-ектов, перемещения на плоскости,\n" +
                " изменения размеров и поворота на задан-ный угол.\n");
            read();
        }


        private static void laba3()
        {
            message("В массив A[N] занесены натуральные числа.\n" +
                    " Найти сумму элементов, крат-ных данному К.");
            message("input size array!");
            message("arr[N]: ", false);
            int N = int.Parse(read());

            Console.Write("K: ");
            int K = int.Parse(read());

            int[] arr = new int[N];
            Random rnd = new Random();

            for (int i = 0; i < arr.Length; i++)
            {
                arr[i] = rnd.Next(1, 101);
                if (i == 4)
                {
                    message(arr[i] + " ", false);

                    message();
                    continue;
                }

                message(arr[i] + " ", false);
            }

            int sum = 0;

            for (int i = 0; i < arr.Length; i++)
            {
                if (arr[i] % K == 0) sum += arr[i];
            }

            message();
            message("Otvet: " + sum);

            read();
        }

        private static void laba4()
        {
            message("Реализовать интерфейсы и показать их работоспособность. " +
                    "Ввод данных должен производиться с клавиатуры");
            Square sqr = new Square(10);
            sqr.draw();

            Console.ReadKey();
            sqr.x1 = 15;

            sqr.draw();

            Console.ReadKey();

            Restangle res = new Restangle(20, 10);
            res.draw();

            Console.ReadKey();

            Circle circ = new Circle(40, 10, 8);
            circ.draw();

            Console.ReadLine();
        }

        private static void laba5()
        {
            // создаем банковский счет
            Restangle account = new Restangle(200);
            // Добавляем в делегат ссылку на метод Show_Message
            // а сам делегат передается в качестве параметра метода RegisterHandler
            account.RegisterHandler(new Restangle.AccountStateHandler(Show_Message));
            // Два раза подряд пытаемся снять деньги
            account.Withdraw(100);
            account.Withdraw(150);
            Console.ReadLine();
        }

        private static void Show_Message(String message)
        {
            Console.WriteLine(message);
        }


        private static void laba6()
        {
            string path = @"D:\test.txt";
            try
            {
                message("************FULL**********");
                using (StreamReader sr = new StreamReader(path))
                {
                    message(sr.ReadToEnd());
                }

                message();

                Square sq = new Square();
                sq.x1 = Convert.ToInt32(read());

                Restangle res = new Restangle(10, 20);
                using (StreamWriter sw = new StreamWriter(path, true, System.Text.Encoding.Default))
                {
                    sw.WriteLine(sq.x1);
                    /*  sw.WriteLine("Перменная прямоугольника height = " + res.height);
                      sw.WriteLine("Перменная прямоугольника width = " + res.width);*/
                }


                message("************LINE**********");
                using (StreamReader sr = new StreamReader(path, System.Text.Encoding.Default))
                {
                    string line;

                    while ((line = sr.ReadLine()) != null)
                    {
                        sq.x1 = Convert.ToInt32(line);

                        if (sr.ReadLine() == null)
                        {
                            message("Перменная квадрата X1 = " + sq.x1);
                        }
                    }
                }

                Console.ReadLine();
            }
            catch (Exception ex)
            {
                message(ex.Message);
            }
        }


        private static void message(string text = "", bool line = true)
        {
            if (line)
            {
                Console.WriteLine(text);
            }
            else
            {
                Console.Write(text);
            }
        }

        private static string read()
        {
            return Console.ReadLine();
        }
    }
}