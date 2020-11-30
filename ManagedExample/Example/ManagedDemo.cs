using System;
using System.Collections.Generic;
using System.Text;
using olc.managed;


namespace Example
{
    public class ManagedDemo : PixelGameEngineManaged
    {
        public override bool OnUserCreate()
        {
            // Called once at the start, so create things here
            olcPGEXSoundManaged.InitialiseAudio();

            var test  = new vf2dm(2f,2f);

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

            if (GetKey(KeyManaged.A).bHeld)
            {
                DrawString(3, 20, "A Held", PixelColor.BLACK);
            }

            if (GetKey(KeyManaged.Q).bPressed)
            {
                DrawString(3, 30, "Q Pressed", PixelColor.BLACK);
            }

            return true;
        }

        public override bool OnUserDestroy()
        {
            olcPGEXSoundManaged.DestroyAudio();
            return true;
        }
    }
}
