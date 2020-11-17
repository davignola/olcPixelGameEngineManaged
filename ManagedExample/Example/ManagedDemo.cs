using System;
using System.Collections.Generic;
using System.Text;
using olc.wrapper;


namespace Example
{
    public class ManagedDemo : PixelGameEngineManaged
    {
        public override bool OnUserCreate()
        {
            // Called once at the start, so create things here
            return true;
        }

        public override bool OnUserUpdate(float fElapsedTime)
        {
            var rand = new Random();
            // called once per frame
            for (int x = 0; x < ScreenWidth(); x++)
                for (int y = 0; y < ScreenHeight(); y++)
                    Draw(x, y, new PixelManaged(Convert.ToByte(rand.Next() % 255), Convert.ToByte(rand.Next() % 255), Convert.ToByte(rand.Next() % 255)));

            DrawString(3, 10, "HELLO WORLD!", PixelColor.BLACK);
            return true;
        }

        public override bool OnUserDestroy()
        {
            return true;
        }
    }
}
