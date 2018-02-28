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


        private static void menu()
        {
           
            while (true)
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
                
                int value = int.Parse(Console.ReadLine());
               
                switch (value)
                {
                    case 1:
                        laba1();
                        break;
                    case 2:
                        break;
                    case 3:
                        laba3();
                        break;
                    case 4:
                        break;
                    case 5:
                        break;
                    case 6:
                        break;
                    case 7:
                        break;
                    case 8:
                        break;
                            
                                
                }
                
            }
        }
        
        
        
        private static void laba2()
        {
           
            
            
        } 
        
        
        
        
        private static void laba3()
        {
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