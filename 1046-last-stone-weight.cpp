class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;

        for (int i = 0; i < stones.size(); i++) {
            maxHeap.push(stones[i]);
        }

        while (!maxHeap.empty()) {
            int stone_one = maxHeap.top();
            maxHeap.pop();
        
            if (maxHeap.empty()) {
                return stone_one;
            }

            int stone_two = maxHeap.top();
            maxHeap.pop();

            int result = stone_one - stone_two;

            if (result) {
                maxHeap.push(result);
            }
        }

        return 0;
    }
};
