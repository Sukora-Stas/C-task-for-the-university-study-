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

        public void draw()
        {
        }

        public void move(int x1, int x2, int y1, int y2)
        {
            this.x1 = x1;
            this.y1 = y1;
            this.x2 = x2;
            this.y2 = y2;
        }

        public void move(int x, int y)
        {
            throw new System.NotImplementedException();
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