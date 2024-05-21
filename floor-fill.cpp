class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int startColor = image[sr][sc];

        performFill(image, sr, sc, color, startColor);

        return image;
    }
    
   
    void performFill(vector<vector<int>>& image, int x, int y, int color, int startColor) 
    {
        if (image[x][y] != color) 
        {
            image[x][y] = color;
        }
        
        vector<std::pair<int, int>> possibleSquares = getAllPossibleSquares(x, y, image, color, startColor);

        for (int i = 0; i < possibleSquares.size(); i++) 
        {
            performFill(image, possibleSquares[i].first, possibleSquares[i].second, color, startColor);
        }
    }

    vector<std::pair<int, int>> getAllPossibleSquares(int x, int y, vector<vector<int>>& image, int color, int startColor) 
    {
        vector<std::pair<int, int>> possibleSquares;

        if (x - 1 >= 0) 
        {
            if (image[x - 1][y] != color && image[x - 1][y] == startColor) 
            {
                possibleSquares.push_back({ x - 1,y });
            }
        }

        if (x + 1 <= image.size() - 1) 
        {
            if (image[x + 1][y] != color && image[x + 1][y] == startColor) 
            {
                possibleSquares.push_back({ x + 1, y });
            }
        }

        if (y - 1 >= 0) 
        {
            if (image[x][y - 1] != color && image[x][y - 1] == startColor) 
            {
                possibleSquares.push_back({ x,y - 1 });
            }
        }

        if (y + 1 <= image[x].size() - 1) 
        {
            if (image[x][y + 1] != color && image[x][y + 1] == startColor) 
            {
                possibleSquares.push_back({ x,y + 1 });
            }
        }

        return possibleSquares;

    }
};
