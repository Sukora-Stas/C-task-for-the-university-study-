namespace YIP
{
    public class Circle : Figure2D
    {
        private int x { get; set; }
        private int y { get; set; }

        public Circle()
        {
        }

        public void draw()
        {
            throw new System.NotImplementedException();
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