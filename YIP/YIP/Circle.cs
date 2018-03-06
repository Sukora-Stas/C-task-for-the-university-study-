using System;

namespace YIP
{
    public class Circle : Figure2D
    {
        public int centerX { get; set; }
        public int centerY { get; set; }
        public int radius { get; set; }

        public Circle()
        {
        }

        public Circle(int centerX, int centerY, int radius)
        {
            this.centerX = centerX;
            this.centerY = centerY;
            this.radius = radius;
        }


        public void draw()
        {
            Action<int, int> write = (xp, yp) =>
            {
                Console.SetCursorPosition(xp, yp);
                Console.Write("*");
            };

            int x = -radius;
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

        public void move(int x1, int x2, int y1, int y2)
        {
           
        }

        public void scale(int scale)
        {
            throw new System.NotImplementedException();
        }

        public void Rotate(double radius)
        {
        }
    }
}