public class Solution {
    public string MergeAlternately(string word1, string word2) {
        bool firstLonger = word1.Length >= word2.Length; 
        int firstCounter = 0;
        int secondCounter = 0;
        string result = "";


        while (firstCounter < word1.Length && secondCounter < word2.Length) {
            result += word1[firstCounter];
            result += word2[secondCounter];

            firstCounter++;
            secondCounter++;
        }

        if (firstLonger) {
            while (firstCounter < word1.Length) {
                result += word1[firstCounter];
                firstCounter++;
            }
        }
        else {
            while (secondCounter < word2.Length) {
                result += word2[secondCounter];
                secondCounter++;
            }
        }

        return result;
    }
}
