class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> friends;

        // 1) First, insert all of the elements into the queue
        for (int i = 1; i < n + 1; ++i) {
            friends.push(i);
        }

        int counter = 1;

        // 2) do the circular motion
        while (friends.size() > 1) {
            int first = friends.front();
            friends.pop();

            if (counter != k) {
                friends.push(first);
                counter++;
            } else {
                counter = 1;
            }
        }

        return friends.front();
    }
};
