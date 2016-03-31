using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.Sql;
using System.Data.SqlClient;
namespace Connection_test
{
    public partial class Form1 : Form
    {
        SqlConnection myConnection;
      
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            SqlCommand showdata = new SqlCommand("SELECT * FROM People",myConnection);

            try
            {
                SqlDataAdapter sda = new SqlDataAdapter();
                sda.SelectCommand = showdata;
                DataTable dbatest = new DataTable();
                sda.Fill(dbatest);
                BindingSource bSource = new BindingSource();
                bSource.DataSource = dbatest;
                dataGridView1.DataSource = bSource;
                sda.Update(dbatest);
            }
            catch(Exception ex)
            {
                MessageBox.Show("sory");
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            try
            {
                SqlParameter name = new SqlParameter("@name", SqlDbType.NVarChar, 50);
                SqlParameter adress = new SqlParameter("@adres", SqlDbType.NVarChar, 50);
                name.Value = textBox1.Text;
                adress.Value = textBox2.Text;
                SqlCommand myCommand = new SqlCommand("INSERT INTO People (Name, Adress) " +
                                       "Values (@name, @adres)", myConnection);
                myCommand.Parameters.Add(name);
                myCommand.Parameters.Add(adress);
                myCommand.ExecuteNonQuery();
            }
            catch(Exception ex)
            {
                MessageBox.Show("failed to add");
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            try
            {
                myConnection = new SqlConnection("user id=userid;" +
                                     "password=validpassword;server=RONALD\\SQLSHCOOL;" +
                                     "Trusted_Connection=yes;" +
                                     "database=Mock; " +
                                     "connection timeout=15");
                myConnection.Open();


            }
            catch (Exception ex)
            {
                MessageBox.Show("wrong");
            }

        }

        private void Form1_closed(object sender, FormClosedEventArgs e)
        {
            try
            {
                myConnection.Close();
            }
            catch (Exception ex)
            {
                MessageBox.Show("Connection was not close or created");
            }
            
        }
    }
}
