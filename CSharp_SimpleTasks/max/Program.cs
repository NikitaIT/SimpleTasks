using System;
using System.Collections.Generic;
using System.Diagnostics.Eventing.Reader;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace max
{
    class Program
    {
        static void Main(string[] args)
        { 
            List<int> q = new List<int>();
            int x;
            while ((x = Convert.ToInt32(Console.ReadLine()))!=0)
            {
                q.Add(x);
            }
            List<int> QList = new List<int>();
            for (int i = 0; i < q.Count; i++)
            {
                QList.Clear();
                QList.Add(0);
                QList.Add(1);
                for (int j = 2; j <= q[i]; j++)
                {
                    if (j%2 == 0) QList.Add(QList[j/2]);
                    else
                    {
                        QList.Add(QList[(j - 1)/2 + 1] + QList[(j - 1)/2]);
                    }
                }
                Console.WriteLine(QList.Max());
            }
            Console.ReadKey();
        }
    }
}
