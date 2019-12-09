using System;
using System.Text;

namespace System
{
    public class Program
    {
        public static string ReverseWords(string input)
        {
            StringBuilder sb = new StringBuilder();
            string[] words = input.Split(new char[] {' '}, StringSplitOptions.RemoveEmptyEntries);
            if (words.Length < 1)
                return "";
            for (int i = words.Length - 1; i > 0; i--)
            {
                sb.Append(words[i]);
                sb.Append(' ');
            }
            sb.Append(words[0]);
            return sb.ToString();
        }
        
        public static void Main(string[] args)
        {
            string result = ReverseWords( Console.ReadLine() );
            Console.WriteLine(result);
        }
    }
}
