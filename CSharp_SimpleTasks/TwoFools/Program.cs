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
            Console.WriteLine((Convert.ToInt32(x[1])-1) + " " + (Convert.ToInt32(x[0])-1));
        }
    }
}
