using System;
using olc.managed;

namespace Example
{
    public class Program
    {
        static void Main(string[] args)
        {
            var demo = new ManagedDemo();
            if (demo.Construct(100, 100, 4, 4) == rcodeManaged.OK)
                demo.Start();

        }
    }
}
