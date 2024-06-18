class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        
        if (difficulty.size() != profit.size()) {
            return 0;
        }

        std::vector<pair<int, int>> jobs;
        int pointer = 0;

        while (pointer < difficulty.size()) {
            jobs.push_back({profit[pointer], difficulty[pointer]});
            pointer++;
        }

        priority_queue<pair<int,int>> mostProfit;

        for (int i = 0; i < jobs.size(); ++i) {
            mostProfit.push(jobs[i]);
        }

        std::sort(worker.begin(), worker.end());
        int totalSum = 0;

        for (int i = worker.size() - 1; i >= 0; --i) {
            while (!mostProfit.empty()) {
                pair<int,int> front = mostProfit.top();

                if (worker[i] >= front.second) {
                    totalSum += front.first;
                    break;
                } 

                mostProfit.pop();
            }
        }

        return totalSum;

    }
 

};
