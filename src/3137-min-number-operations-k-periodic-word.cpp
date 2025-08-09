class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        // Count all pairs that fit in the mentioned criteria
        // Take the ones that occur the most
        // Go over them and do replacement and count how many times you need to replace.
        // Take the smallest number

        std::unordered_map<std::string, int> substringCounter; 
        int pointer = 0; 


        // Count all of the substrings
        while (pointer < word.size()) {
            if (pointer % k == 0) {
                if (pointer + k > word.size()) {
                    break;
                }

                std::string substring;

                for (int i = pointer; i < pointer + k; ++i) {
                    substring += word[i];
                }

                substringCounter[substring]++;
            }

            pointer += k;
        }

        // Go over all substrings and select the ones that occur the most frequently
        int biggestOccurance = 0;
        for (auto& pair : substringCounter) {
            biggestOccurance = std::max(pair.second, biggestOccurance);
        }

        return (word.size() / k) - biggestOccurance;
    }
};
