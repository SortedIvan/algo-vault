class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islandId = 0;
        std::map<pair<int, int>, int> islandIdMap;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    bool inserted = false;
                    findIsland(islandIdMap, i, j, grid, islandId, inserted);
                    if (inserted)
                    {
                        islandId++;
                    }
                }
            }
        }

        return islandId;

    }
    
    void findIsland(std::map<pair<int,int>, int>& islandIdMap, int x, int y, vector<vector<char>>& grid, int id, bool& inserted)
    {
        if (islandIdMap.find({x,y}) != islandIdMap.end())
        {
            return;
        }

        inserted = true;
        islandIdMap.insert({{x,y},id});

        // check left, up, down, right

      if (x - 1 >= 0) 
        {
            if (grid[x - 1][y] == '1') 
            {
               if (islandIdMap.find({x-1, y}) == islandIdMap.end())
               {
                    findIsland(islandIdMap, x - 1, y, grid, id, inserted);
               }
            }
        }

        if (x + 1 <= grid.size() - 1) 
        {
            if (grid[x + 1][y] == '1') 
            {
               if (islandIdMap.find({x+1, y}) == islandIdMap.end())
               {
                    findIsland(islandIdMap, x + 1, y, grid, id, inserted);
               }
            }
        }

        if (y - 1 >= 0) 
        {
            if (grid[x][y - 1] == '1') 
            {
               if (islandIdMap.find({x, y - 1}) == islandIdMap.end())
               {
                    findIsland(islandIdMap, x, y - 1, grid, id, inserted);
               }
            }
        }

        if (y + 1 <= grid[x].size() - 1) 
        {
            if (grid[x][y + 1] == '1') 
            {
               if (islandIdMap.find({x, y + 1}) == islandIdMap.end())
               {
                    findIsland(islandIdMap, x, y + 1, grid, id, inserted);
               }
            }
        } 
    }
};
