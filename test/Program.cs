using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace test
{
    class Program
    {
        static void Main(string[] args)
        {
            play_9();
            //radians_10();
            //tictactoe_12();
            System.Console.ReadKey();
        }

        static void play_9()
        {
            StreamReader sr = new StreamReader("play.dat");
            string[] widths = sr.ReadLine().TrimEnd().Split(' ');

            for (int k = 0; k < widths.Length; k++)
            {
                int width = Int32.Parse(widths[k]);
                for (int i = 0; i < width; i++)
                {
                    for (int j = 1; j <= (2 * i) + 1; j++)
                    {
                        Console.Write("*");
                    }
                    Console.Write("\n");
                }
                for (int i = width - 2; i >= 0; i--)
                {
                    for (int j = (2 * i) + 1; j > 0; j--)
                    {
                        Console.Write("*");
                    }
                    Console.Write("\n");
                }
                Console.Write("\n");
            }
        }

        static void radians_10()
        {
            StreamReader sr = new StreamReader("radians.dat");
            while (!sr.EndOfStream)
            {
                double deg = Double.Parse(sr.ReadLine().TrimEnd());
                double rad = deg / 180;
                if (deg == 180) { System.Console.WriteLine(((int)deg).ToString() + " degrees = PI radians"); continue; }
                if (deg % 180 == 0) { System.Console.WriteLine(((int)deg).ToString() + " degrees = " + ((int)rad).ToString() + "PI radians"); continue; }
                System.Console.WriteLine(((int)deg).ToString() + " degrees = " + ((double)rad).ToString("0.00") + "PI radians"); continue;
            }
        }

        static void tictactoe_12() {
            StreamReader sr = new StreamReader("tictactoe.dat");
            int count = Int32.Parse(sr.ReadLine().ToString().TrimEnd());
            for (int i = 0; i < count; i++)
            {
                bool done = false;
                bool comp = true;
                char[,] a = new char[3, 3];
                for (int j = 0; j < 9; j++)
                {
                    a[j / 3, j % 3] = (char)sr.Read();
                    if (a[j / 3, j % 3] == '*') { comp = false; }
                }

                for (int j = 0; j < 3; j++)
                {
                    if (((a[j, 0] == a[j, 1]) && (a[j, 1] == a[j, 2])) && (a[j,0] != '*')) { System.Console.WriteLine(a[j, 0]); done = true; break; }
                }
                if (done) { continue; }
                for (int j = 0; j < 3; j++)
                {
                    if (((a[0, j] == a[1, j]) && (a[1, j] == a[2, j])) && (a[0,j] != '*')) { System.Console.WriteLine(a[0, j]); done = true; break; }
                }
                if (done) { continue; }
                if (((a[0, 0] == a[1, 1]) && (a[1, 1] == a[2, 2])) && (a[0,0] != '*')) { System.Console.WriteLine(a[0,0]); done = true; continue; }
                if (((a[0, 2] == a[1, 1]) && (a[2, 0] == a[1, 1])) && (a[0,2] != '*')) { System.Console.WriteLine(a[0,2]); done = true; continue; }
                
                //check tie
                if (comp) { System.Console.WriteLine("TIE"); } else
                { System.Console.WriteLine("INC"); }
                sr.ReadLine();
            }
        }
    }
}
