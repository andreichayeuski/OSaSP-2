using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using ActiveXCPP2Lib;            //не забудьте добавить строки подключения
using AxActiveXCPP2Lib;


namespace MyForm
{
    public partial class Form1 : Form
    {
        static double k = 10;
        public Form1()
        {
            InitializeComponent();
            k = axActiveXCPP21.TestMyMethod(12);
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Радиус Круга:" + k);
        }

    }
}
