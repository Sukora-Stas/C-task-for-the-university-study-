using System;

namespace YIP
{
    public class Restangle : Figure2D
    {
        public int height {
            get;

            set; }
        public int width { get; set; }


        int _sum; // Переменная для хранения суммы

        public Restangle(int height, int width)
        {
            this.height = height;
            this.width = width;

           
        }

        // Объявляем делегат
        public delegate void AccountStateHandler(string message);
        // Создаем переменную делегата
        AccountStateHandler _del;

        // Регистрируем делегат
        public void RegisterHandler(AccountStateHandler del)
        {
            _del = del;
        }

        public Restangle()
        {
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
            if (_del != null)
                _del($"Поворачиваем на {x1} градусов");
        }


        public void scale(int scale)
        {
            if (_del != null)
                _del($"Изменяем размер на {scale}");
        }

        public void Rotate(double radius)
        {
                if (_del != null)
                    _del($"Поворачиваем на {radius} градусов");
        }
    }
}