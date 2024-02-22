public class Solution {
    public bool IsPalindrome(string s) {
        s = s.ToLower();
        List<char> parsedInput = ParseInput(s);

        int leftPointer = 0;
        int rightPointer = parsedInput.Count - 1;

        while (leftPointer < rightPointer) {
            if (parsedInput[leftPointer] != parsedInput[rightPointer]){
                return false;
            }
            leftPointer++;
            rightPointer--;
        }

        return true;
    }

     public List<char> ParseInput(string s) {
        	s = s.ToLower();
			List<char> result = new List<char>(s);
			for (int i = 0; i < s.Length; i++) {
				if ((s[i] >= 97 && s[i] <= 122)
                || (s[i] >= 48 && s[i] <= 57)) {
					continue;
				}
				result.Remove(s[i]);
			}

			return result;
    }
}
