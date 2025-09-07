class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> visited;
        queue<int> bfs;
        int numberOfRoomsVisited = 0;

        bfs.push(0);

        while (!bfs.empty()) {
            int nextRoom = bfs.front();
            bfs.pop();

            if (visited.find(nextRoom) != visited.end()) {
                continue;
            }

            visited.insert(nextRoom);
            numberOfRoomsVisited++;

            for (int i = 0; i < rooms[nextRoom].size(); ++i) {
                int key = rooms[nextRoom][i];

                if (visited.find(key) != visited.end()) {
                    continue;
                }

                bfs.push(key);
            }
        }

        return numberOfRoomsVisited == rooms.size();
    }
};
