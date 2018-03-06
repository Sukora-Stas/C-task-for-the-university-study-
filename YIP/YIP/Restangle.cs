using System;

namespace YIP
{
    public class Restangle : Figure2D
    {
        private int height { get; set; }
        private int width { get; set; }


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