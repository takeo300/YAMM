using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

using System.Runtime.InteropServices;

namespace Skype
{
    public partial class Form1 : Form
    {
        public struct databuffer
        {
            public string data;
            public Boolean valid;
        }

        public static readonly IntPtr HWND_BROADCAST = new IntPtr(-1);
        public static readonly uint WM_COPYDATA = 0x004a;

        public databuffer skypedata; 
        public UInt32 APIDiscover;
        public UInt32 APIAttach;

        private IntPtr HSkype = IntPtr.Zero;

        public enum SkypeAttachStatus : uint
        {
            Success = 0,
            PendingAuthorizaion = 1,
            Refused = 2,
            NotAvailable = 3,
            Available = 0x8001
        }

        [StructLayout(LayoutKind.Sequential)]
        public struct CopyDataStruct
        {
            public string ID;
            public int Length;
            public string Data;
        }


        
        [DllImport("user32.dll",
         SetLastError = true, 
         CharSet = CharSet.Auto)]
        static extern uint RegisterWindowMessage(
            string lpString);


        [DllImport("user32.dll")]
        public static extern IntPtr SendMessageTimeout(
            IntPtr windowHandle,
            uint Msg,
            IntPtr wParam,
            IntPtr lParam,
            SendMessageTimeoutFlags flags,
            uint timeout,
            out IntPtr result);

        [DllImport("user32.dll")]
        public static extern IntPtr SendMessageTimeout(
            IntPtr windowHandle,
            uint Msg,
            IntPtr wParam,
            ref CopyDataStruct lParam,
            SendMessageTimeoutFlags flags,
            uint timeout,
            out IntPtr result);


        [Flags]
        public enum SendMessageTimeoutFlags : uint
        {
            SMTO_NORMAL = 0x0000,
            SMTO_BLOCK = 0x0001,
            SMTO_ABORTIFHUNG = 0x0002,
            SMTO_NOTIMEOUTIFNOTHUNG = 0x0008
        }

        
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            SkypeFirstConnect();
            IntPtr result = SendCommand("CALL echo123");
            WaitForSkype("INPROGRESS");

            string CallID = getCallId();
            string filename = @"""c:\test.wav"" ";
            string cmd = "ALTER CALL " + CallID + " SET_OUTPUT file=" + filename;
            result = SendCommand(cmd);
            WaitForSkype("FINISHED");

        }

        private void SkypeFirstConnect()
        {


            APIDiscover = RegisterWindowMessage(
                    "SkypeControlAPIDiscover");
            APIAttach = RegisterWindowMessage(
                "SkypeControlAPIAttach");

        
            skypedata.valid = false;
            skypedata.data = string.Empty;
            IntPtr result;
            IntPtr aRetVal = SendMessageTimeout(
                HWND_BROADCAST,
                APIDiscover,
                this.Handle,
                IntPtr.Zero,
                SendMessageTimeoutFlags.SMTO_NORMAL,
                100,
                out result);

            WaitForSkype("");
        }

        protected override void WndProc(ref Message m)
        {

            if ((UInt32)m.Msg == APIAttach)
            {

                SkypeAttachStatus Status = (SkypeAttachStatus)m.LParam;
                textBox1.Text += "Status=" + Status.ToString() + Environment.NewLine;
                if (Status == SkypeAttachStatus.Success)
                {
                    HSkype = m.WParam;

                }
                if (Status == SkypeAttachStatus.Available)
                {
                    skypedata.valid = true;
                }
                m.Result = new IntPtr(1);
                return;
            }


           
            if ((UInt32)m.Msg == WM_COPYDATA)
            {
                if (m.WParam == HSkype)
                {
                    CopyDataStruct data = (CopyDataStruct)m.GetLParam(typeof(CopyDataStruct));
                    skypedata.data = data.Data;
                    m.Result = new IntPtr(1);
                    textBox1.Text += "Skype data=" + skypedata.data + Environment.NewLine;
                    skypedata.valid = true;
                    return;
                }
            }
           
            base.WndProc(ref m);

        }

        private void WaitForSkype(string target)
        {
            do
            {
                do
                {
                    Application.DoEvents();
                } while (!skypedata.valid);
            } while (!skypedata.data.Contains(target));


        }
        public IntPtr SendCommand(string Command)
        {
            skypedata.valid = false;
            skypedata.data = string.Empty;
            CopyDataStruct data = new CopyDataStruct();

            data.ID = "1";
            data.Data = Command;
            data.Length = data.Data.Length + 1;

            IntPtr result;
            IntPtr RetVal = SendMessageTimeout(
                HSkype,
                WM_COPYDATA,
                this.Handle,
                ref data,
                SendMessageTimeoutFlags.SMTO_NORMAL,
                100,
                out result);

            return RetVal;
        }
        private string getCallId()
        {
            string[] items = skypedata.data.Split(' ');
            return items[1];
        }
    }
}