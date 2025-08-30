struct RectangleProperties {
private:
    float calculateRectangleDiagonal(int a, int b) {
        return std::sqrt(a * a + b * b);
    }
public:
    float rectangleDiagonalSize;
    int rectangleArea;

    RectangleProperties(float rectangleDiagonalSize, int rectangleArea) {
        this->rectangleDiagonalSize = rectangleDiagonalSize;
        this->rectangleArea = rectangleArea;
    }

    RectangleProperties(int a, int b) {
        this->rectangleDiagonalSize = calculateRectangleDiagonal(a, b);
        this->rectangleArea = a * b;
    }
};

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        vector<RectangleProperties> rectangleProperties;
        float currentBiggestDiagonalSize = std::numeric_limits<float>::min();

        for (int i = 0; i < dimensions.size(); ++i) {
            auto rectProperties = RectangleProperties(dimensions[i][0], dimensions[i][1]);
            currentBiggestDiagonalSize = std::max(rectProperties.rectangleDiagonalSize, 
                                                  currentBiggestDiagonalSize);
            rectangleProperties.push_back(rectProperties);
        }

        int numberOfRectanglesWithMaxDiagonal = 0;
        int maxArea = 0;
        int areaOfLastEncountered = 0;
        for (int i = 0; i < rectangleProperties.size(); ++i) {
            if (rectangleProperties[i].rectangleDiagonalSize == currentBiggestDiagonalSize) {
                numberOfRectanglesWithMaxDiagonal++;
                maxArea = std::max(rectangleProperties[i].rectangleArea, maxArea);
                areaOfLastEncountered = rectangleProperties[i].rectangleArea;
            }
        }

        if (numberOfRectanglesWithMaxDiagonal > 1) {
            return maxArea;
        }
    
        return areaOfLastEncountered;
    }


};
