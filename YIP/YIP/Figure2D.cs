using System.Runtime.CompilerServices;
using System.Security.Cryptography.X509Certificates;

namespace YIP
{
    public interface Figure2D
    {
        void draw();

        void move(int x1, int x2, int y1, int y2);

        void move(int x, int y);

        void scale(int scale);

        void Rotate(double radius);
    }
}