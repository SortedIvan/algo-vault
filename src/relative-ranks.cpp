#include <queue>

class Compare {
public:
    bool operator()(std::pair<int,int> first, std::pair<int,int> second)
    {
        return first.first < second.first;
    }
};


class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        // we can build a max heap
        // This has to be custom, as we need to store a pair of values

        std::priority_queue<std::pair<int,int>, vector<std::pair<int, int>>, Compare> queue;
        std::vector<string> result(score.size());

        for (int i = 0; i < score.size(); i++)
        {
            queue.push(std::make_pair(score[i], i));
        }

        int rankPointer = 1;

        while (!queue.empty()) {
            
            if (rankPointer == 1)
            {
                result[queue.top().second] = "Gold Medal";
            }
            else if (rankPointer == 2)
            {
                result[queue.top().second] = "Silver Medal";
            }
            else if (rankPointer == 3)
            {
                result[queue.top().second] = "Bronze Medal";             
            }
            else
            {
                result[queue.top().second] = std::to_string(rankPointer);
            }

            rankPointer++;
            queue.pop();
            continue;
        }

        return result;

    }
};
