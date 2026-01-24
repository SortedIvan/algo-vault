class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int> pq;

        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        }

        int counter = 1;
        while (counter != k && !pq.empty()) {
            pq.pop();
            counter++;
        }

        return pq.top();
    }
};
