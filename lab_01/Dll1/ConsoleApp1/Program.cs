using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Program
    {
        [DllImport("DLL1.dll", EntryPoint = "GetTime")]
        public static extern int GetTime();


        [STAThread]
        static void Main(string[] args)
        {
            GetTime();
            Console.ReadLine();
        }

    }
}
