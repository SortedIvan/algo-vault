class Node {
public:
    int x;
    int y;
    int dist;

    Node(int _x, int _y, int _dist) {
        x = _x;
        y = _y;
        dist = _dist;
    }
};

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<Node> bfs;
        vector<vector<int>> visited;

        for (int i = 0; i < mat.size(); ++i) {
            
            vector<int> row;
            
            for (int k = 0; k < mat[i].size(); k++) {
                row.push_back(0);
                
                if (mat[i][k] == 0) {
                    Node node(i, k, 0);
                    bfs.push(node);
                }
            }

            visited.push_back(row);
        }


        while (!bfs.empty()) {
            Node front = bfs.front();
            bfs.pop();

            if (mat[front.x][front.y] == 0) {
                visited[front.x][front.y] = 1;
            }

            mat[front.x][front.y] = front.dist;

            if (front.x - 1 >= 0) {
                if (!visited[front.x - 1][front.y]) {
                    if (mat[front.x - 1][front.y] == 1) {
                        visited[front.x - 1][front.y] = 1;
                        Node add(front.x-1, front.y, front.dist + 1);
                        bfs.push(add);
                    }
                }
            }

            if (front.x + 1 < mat.size()) {
                if (!visited[front.x + 1][front.y]) {
                    if (mat[front.x + 1][front.y] == 1) {
                        visited[front.x + 1][front.y] = 1;
                        Node add(front.x+1, front.y, front.dist + 1);
                        bfs.push(add);
                    }
                }
            }

            if (front.y - 1 >= 0) {
                if (!visited[front.x][front.y - 1]) {
                    if (mat[front.x][front.y - 1] == 1) {
                        visited[front.x][front.y - 1] = 1;
                        Node add(front.x, front.y - 1, front.dist + 1);
                        bfs.push(add);
                    }
                }
            }

            if (front.y + 1 < mat[front.x].size()) {
                if (!visited[front.x][front.y + 1]) {
                    if (mat[front.x][front.y + 1] == 1) {
                        visited[front.x][front.y + 1] = 1;
                        Node add(front.x, front.y + 1, front.dist + 1);
                        bfs.push(add);
                    }
                }
            }

        }

        return mat;
        
    }
};
