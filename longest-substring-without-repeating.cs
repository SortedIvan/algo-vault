public class Solution {
    
	public int LengthOfLongestSubstring(string s) {

			if (s.Length == 0) {
				return 0;
			}

			if (s.Length == 1) {
				return 1;
			}

			int currentBiggest = 0;
			int biggest = 0;
			bool biggestWasSet = false;
			Dictionary<char, int> chars = new Dictionary<char, int>();	
			for (int i = 0; i < s.Length; i++) {
				if (biggestWasSet) {
					chars = new Dictionary<char,int>();
					biggestWasSet = false;
				}

				for (int k = i; k < s.Length; k++) {
					bool keyExists = chars.ContainsKey(s[k]);

					if (keyExists) {
						if (biggest < currentBiggest){ 
							biggest = currentBiggest;
						}
						biggestWasSet = true;
						currentBiggest = 0;
						break;
					}
					else {
						currentBiggest++;
						chars.Add(s[k], 1);
					}

				}
			}    
			
			return biggest;
		}
}
