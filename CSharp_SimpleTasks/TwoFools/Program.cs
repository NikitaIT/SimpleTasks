using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TwoFools
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] x = Console.ReadLine().Split(' ');
            Console.WriteLine((10 - Convert.ToInt32(x[0])) + " " + (10 - Convert.ToInt32(x[1])));
        }
    }
}
