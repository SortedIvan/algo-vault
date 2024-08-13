class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int>> result;
        std::set<std::vector<int>> frequencyCount;

        for (int i = 0; i < candidates.size(); ++i) {
            vector<int> frequency(41, 0);
            frequency[candidates[i]] = 1;
            vector<int> currentCombination = {candidates[i]};
            getAllCombinations(frequencyCount, frequency, candidates, result, target, currentCombination, candidates[i]);
        }

        return result;
    }

    void getAllCombinations(std::set<vector<int>>& frequencyCount, vector<int> currFrequency, vector<int>& candidates, std::vector<vector<int>>& result, int target, vector<int> currentCombination, int currentSum) {
        
        if (currentSum > target) {
            return;
        }

        if (currentSum == target) {
            result.push_back(currentCombination);
            return;
        }

        for (int i = 0; i < candidates.size(); ++i) {
            vector<int> newCombination = currentCombination;
            vector<int> newFrequency = currFrequency;

            if (currentSum + candidates[i] > target) {
                continue;
            }

            if (currentSum + candidates[i] == target) { 
                newCombination.push_back(candidates[i]);
                newFrequency[candidates[i]]++;

                if (frequencyCount.find(newFrequency) != frequencyCount.end()) {
                    continue;
                }

                result.push_back(newCombination);
                frequencyCount.insert(newFrequency);
                continue;
            }

            newCombination.push_back(candidates[i]);
            newFrequency[candidates[i]]++;
            getAllCombinations(frequencyCount, newFrequency, candidates, result, target, newCombination, currentSum + candidates[i]);
        }

    }
};
