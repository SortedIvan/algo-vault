using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Collections;
using System.ComponentModel;
using System.Diagnostics.CodeAnalysis;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.Serialization;
using System.Text.RegularExpressions;
using System.Text;
using System;

class Result
{

    /*
     * Complete the 'caesarCipher' function below.
     *
     * The function is expected to return a STRING.
     * The function accepts following parameters:
     *  1. STRING s
     *  2. INTEGER k
     */
     
    static string alphabet = "abcdefghijklmnopqrstuvwxyz";

    public static string caesarCipher(string s, int k)
    {
        string result = "";
        Dictionary<char, char> rotatedAlphabet = new Dictionary<char, char>();
        int asciiStart = 97; // a
        int asciiEnd = 122; //z
        // 1) Convert the alphabet into the rotated alphabet
        for (int i = asciiStart; i < asciiEnd + 1; i++) {
            int position = 0;
            // int overflowedCount = 0;
            if (k + i> asciiEnd) {
                position = k+i;
                while (position > asciiEnd) {
                    position = asciiStart+(position - asciiEnd);
                    position -= 1;
                }
            }
            else {
                position = k + i;
            }
            
            //position = position - overflowedCount;
            
            char newChar = (char)position;
            
            rotatedAlphabet.Add(alphabet[Math.Abs(asciiStart - i)], newChar);
        }

        for (int i = 0; i < s.Length; i++) {
            
            if (s[i] <=90 && s[i] >= 65) {
                result += Char.ToUpper(rotatedAlphabet[Char.ToLower(s[i])]);
                Console.WriteLine(s[i]);
                continue;
            }
            char newChar = '/';
            if (rotatedAlphabet.ContainsKey(s[i])) {
                newChar = rotatedAlphabet[s[i]];          
                result += newChar;
                Console.WriteLine(newChar);
                continue;
            }
            else {
                Console.WriteLine(s[i]);
                result += s[i];
            }
        }
        
        return result;
    }

}

class Solution
{
    public static void Main(string[] args)
    {
        TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

        int n = Convert.ToInt32(Console.ReadLine().Trim());

        string s = Console.ReadLine();

        int k = Convert.ToInt32(Console.ReadLine().Trim());

        string result = Result.caesarCipher(s, k);

        textWriter.WriteLine(result);

        textWriter.Flush();
        textWriter.Close();
    }
}
