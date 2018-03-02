using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace YIP
{
    class Program
    {
        static void Main(string[] args)
        {
            menu();
        }

//TODO:обработчик исключений на ввод(методы)
        private static void menu()
        {
            bool ex = true;
            while (ex)
            {
                Console.Clear();
                Console.WriteLine("Hello man :) Variant 1. \nSukora and Stolpner");
                Console.WriteLine("Please select menu item");
                Console.WriteLine("1: Laba 1");
                Console.WriteLine("2: Laba 2");
                Console.WriteLine("3: Laba 3");
                Console.WriteLine("4: Laba 4");
                Console.WriteLine("5: Laba 5");
                Console.WriteLine("6: Laba 6");
                Console.WriteLine("7: Laba 7");
                Console.WriteLine("8: Laba 8");
                Console.WriteLine("9: Exit");

                int value = int.Parse(Console.ReadLine());

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
                        test();
                        break;
                    case 6:
                        test2();
                        break;
                    case 7:
                        break;
                    case 8:
                        break;
                    case 9:
                        Console.WriteLine("Do you really want to go out? Y/N");
                        string exit = Console.ReadLine();
                        if (exit.ToLower().Equals("y"))
                            ex = false;
                        break;
                    default:
                        Console.WriteLine("Correct you'r input");
                        break;
                }
            }
        }

        private static void test2()
        {
            Action<int, int> write = (xp, yp) => { Console.SetCursorPosition(xp, yp); Console.Write("*"); };
 
            int centerX = 40, centerY = 10, radius = 8, x = -radius;
            while (x < radius)
            {
                var y = (int)Math.Floor(Math.Sqrt(radius * radius - x * x));
 
                write(x + centerX, y + centerY);
                y = -y;
                write(x + centerX, y + centerY);
                x++;
            }
            Console.ReadLine();
        }
        
        private static void test()
        {
            int n = int.Parse(Console.ReadLine());
            var str = new String('*',n);
            Console.WriteLine(str);
            int i=0;
            while (i != n - 2)
            {
                Console.WriteLine("*" + new string(' ', n - 2) + "*");
                i++;
            }
            Console.WriteLine(str);
            Console.ReadLine();
        }


        private static void laba4()
        {
            Console.WriteLine("Реализовать интерфейсы и показать их работоспособность. " +
                              "Ввод данных должен производиться с клавиатуры");
        }

        private static void laba2()
        {
            Console.WriteLine(
                "Построить систему классов для описания плоских геометрических фигур: круга, квадрата, прямоугольника.\n" +
                " Предусмотреть методы для создания объ-ектов, перемещения на плоскости,\n" +
                " изменения размеров и поворота на задан-ный угол.\n");
        }


        private static void laba3()
        {
            Console.WriteLine("В массив A[N] занесены натуральные числа.\n" +
                              " Найти сумму элементов, крат-ных данному К.");
            Console.WriteLine("input size array!");
            Console.Write("arr[N]: ");
            int N = int.Parse(Console.ReadLine());

            Console.Write("K: ");
            int K = int.Parse(Console.ReadLine());

            int[] arr = new int[N];
            Random rnd = new Random();

            for (int i = 0; i < arr.Length; i++)
            {
                arr[i] = rnd.Next(1, 1001);
                if (i == 4)
                {
                    Console.Write(arr[i] + " ");

                    Console.WriteLine();
                    continue;
                }
                Console.Write(arr[i] + " ");
            }

            int sum = 0;

            for (int i = 0; i < arr.Length; i++)
            {
                if (arr[i] % K == 0) sum += arr[i];
            }
            Console.WriteLine();
            Console.WriteLine("Otvet: " + sum);

            Console.ReadLine();
        }


        private static void laba1()
        {
            Console.WriteLine("Используя среду разработки Microsoft Visual Studio,\n" +
                              " создать консоль-ное приложение на языке программирования C#.\n" +
                              " Приложение должно вы-числять значение выражения (см. варианты).\n" +
                              " Ввод данных должен произво-диться с клавиатуры.");
            Console.WriteLine("input variable");
            Console.Write("a: ");
            int a = int.Parse(Console.ReadLine());

            Console.Write("b: ");
            int b = int.Parse(Console.ReadLine());

            Console.Write("c: ");
            int c = int.Parse(Console.ReadLine());


            double sum = 0;

            sum = ((b + Math.Sqrt(Math.Pow(b, 2) + 4 * a * c)) / 2 * a) - Math.Pow(a, 3) * c + Math.Pow(b, -2);


            Console.Write("Otvet: " + sum);


            Console.ReadLine();
        }
    }
}