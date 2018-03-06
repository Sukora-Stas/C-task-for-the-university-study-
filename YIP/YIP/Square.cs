using System;

namespace YIP
{
    public class Square : Figure2D
    {
        private int x1 { get; set; }
        private int y1 { get; set; }
        private int x2 { get; set; }
        private int y2 { get; set; }

        public Square()
        {
        }

        public Square(int x1)
        {
            this.x1 = x1;
        }

        public void draw()
        {
            int n =x1;

            for (int j = 0; j < n; j++)
            {
             Console.Write("* ");   
            }
            
            var str = new String('*', n);
            Console.WriteLine(str);
            int i = 0;
            while (i != n - 2)
            {
                Console.WriteLine("*" + new string(' ', n - 2) + "*");
                i++;
            }
            Console.WriteLine(str);
            Console.ReadLine();
        }

        public void move(int x1, int x2, int y1, int y2)
        {
            this.x1 = x1;
            this.y1 = y1;
            this.x2 = x2;
            this.y2 = y2;
        }


        public void scale(int scale)
        {
            throw new System.NotImplementedException();
        }

        public void Rotate(double radius)
        {
            throw new System.NotImplementedException();
        }
    }
}