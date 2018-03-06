﻿using System;
using System.Collections.Generic;
using System.Diagnostics;
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
                message("1: Laba 1 - done");//
                message("2: Laba 2 - done");//
                message("3: Laba 3 - done");//
                message("4: Laba 4 - done");
                message("5: Laba 5 - 50/50");
                message("6: Laba 6");
                message("7: Laba 7");
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
                        
                        break;
                    case 6:
                        test2();
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

        private static void test2()
        {
            Action<int, int> write = (xp, yp) =>
            {
                Console.SetCursorPosition(xp, yp);
                message("*", false);
            };

            int centerX = 40, centerY = 10, radius = 8, x = -radius;
            while (x < radius)
            {
                var y = (int) Math.Floor(Math.Sqrt(radius * radius - x * x));

                write(x + centerX, y + centerY);
                y = -y;
                write(x + centerX, y + centerY);
                x++;
            }
            Console.ReadLine();
        }


        private static void laba4()
        {
            message("Реализовать интерфейсы и показать их работоспособность. " +
                    "Ввод данных должен производиться с клавиатуры");
            
            Square sqr = new Square(10);
            sqr.draw();
        }

        private static void laba2()
        {
            message(
                "Построить систему классов для описания плоских геометрических фигур: круга, квадрата, прямоугольника.\n" +
                " Предусмотреть методы для создания объ-ектов, перемещения на плоскости,\n" +
                " изменения размеров и поворота на задан-ный угол.\n");
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
                arr[i] = rnd.Next(1, 1001);
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

            sum = ((b + Math.Sqrt(Math.Pow(b, 2) + 4 * a * c)) / 2 * a) - Math.Pow(a, 3) * c + Math.Pow(b, -2);


            message("Otvet: " + sum, false);


            read();
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