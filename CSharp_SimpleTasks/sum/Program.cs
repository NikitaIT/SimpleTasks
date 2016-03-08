using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace sum
{
    class Program
    {
        static void Main(string[] args)
        {
            var x = Convert.ToInt32(Console.ReadLine());
            long sum=0;
            for (var j = 1; j <= Math.Abs(x); j++)
            {
                sum += j;
            }
            Console.WriteLine(Math.Sign(x)*sum + ((Math.Sign(x)==-1)?1:0));
        }
    }
}
