class FindSumPairs {
private:
    unordered_map<int, int> xArrayMap;
    unordered_map<int, int> yArrayMap;

    vector<int> nums1;
    vector<int> nums2;

    void populateArrayMap(unordered_map<int,int>& arrayMap, vector<int>& nums) {
        for (const int num : nums) {
            arrayMap[num]++;
        }
    }

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        populateArrayMap(xArrayMap, nums1);
        populateArrayMap(yArrayMap, nums2);
    
        this->nums1 = nums1;
        this->nums2 = nums2;
    }
    
    void add(int index, int val) {
        int newArrayEntry = nums2[index] + val;
        yArrayMap[nums2[index]]--;

        if (yArrayMap[nums2[index]] == 0) {
            yArrayMap.erase(nums2[index]);
        }

        yArrayMap[newArrayEntry]++;
        nums2[index] = newArrayEntry;
    }
    
    int count(int tot) {
        // y = target - x
        int occuranceSum = 0;
        for (const pair<int,int>& mapEntry : xArrayMap) {
            // {1: 2} means num 1 with 2 occurances
            int y = tot - mapEntry.first;

            if (yArrayMap.find(y) != yArrayMap.end()) {
                occuranceSum += (yArrayMap[y] * mapEntry.second);
            }
        }
    
        return occuranceSum;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
