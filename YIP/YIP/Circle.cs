using System;

namespace YIP
{
    public class Circle : Figure2D
    {
        public int x { get; set; }
        public int y { get; set; }
        public int radius { get; set; }
        public int x2 { get; set; }

        public Circle()
        {
        }


        public void draw()
        {
            Action<int, int> write = (xp, yp) =>
            {
                Console.SetCursorPosition(xp, yp);
                Console.Write("*");
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

        public void move(int x1, int x2, int y1, int y2)
        {
            this.x = x1;
            this.y = y1;
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