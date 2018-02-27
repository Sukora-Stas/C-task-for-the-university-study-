using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace YIP
{
    class Program
    {
        static void Main(string[] args)
        {

            Console.WriteLine("input size array!");
            Console.Write("arr[N]: ");
            int N = int.Parse(Console.ReadLine());

            Console.Write("K: ");
            int K = int.Parse(Console.ReadLine());

            int[] arr = new int[N];
            Random rnd = new Random();

            for (int i = 0; i <arr.Length; i++)
            {
                arr[i] = rnd.Next(1, 1001);
                if (i == 4)
                {
                    Console.Write(arr[i] + " ");

                    Console.WriteLine();
                    continue;
                }
                Console.Write(arr[i]+" ");
            }

            int sum = 0;

            for (int i = 0; i < arr.Length; i++)
            {
                if (arr[i] % K == 0) sum += arr[i];
            }
            Console.WriteLine();
            Console.WriteLine("Otvet: " + sum);

            Console.ReadLine();



            //laba1
            /*  Console.WriteLine("input variable");
              Console.Write("a: ");
              int a = int.Parse(Console.ReadLine());

              Console.Write("b: ");
              int b = int.Parse(Console.ReadLine());

              Console.Write("c: ");
              int c = int.Parse(Console.ReadLine());


              double sum = 0;

              sum = ((b + Math.Sqrt(Math.Pow(b, 2) + 4 * a * c)) / 2 * a) - Math.Pow(a, 3) * c + Math.Pow(b, -2);


              Console.Write("Otvet: " + sum);



              Console.ReadLine();*/
        }
    }
}
