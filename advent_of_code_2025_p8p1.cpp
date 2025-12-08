/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <unordered_set>

struct Point {
    int x;
    int y;
    int z;
    
    Point() = default;
    Point(int x, int y, int z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
};


long long calculateEuclidianDistance(Point p1, Point p2) {
    long long dx = p2.x - p1.x;
    long long dy = p2.y - p1.y;
    long long dz = p2.z - p1.z;
    return dx*dx + dy*dy + dz*dz;
}

struct DistanceBetweenTwoPoints {
    int a_id;
    int b_id;
    long long distance;
    
    DistanceBetweenTwoPoints(Point a, Point b, int a_id, int b_id) {
        distance = calculateEuclidianDistance(a, b);
        this->a_id = a_id;
        this->b_id = b_id;
    }
};

std::vector<DistanceBetweenTwoPoints> parseAndCalculatePointDistances(const std::vector<std::string>& input) {
    std::vector<DistanceBetweenTwoPoints> result;
    std::vector<Point> parsedCoordinates;
    
    // Parse
    for (int i = 0; i < input.size(); ++i) {
        std::vector<int> rowEntry;
        std::string num;
        for (int k = 0; k < input[i].size(); ++k) {
            if (input[i][k] == ',') {
                rowEntry.push_back(std::stoi(num));
                num = "";
            }
            else {
                num.push_back(input[i][k]);
            }
        }
        
        if (!num.empty()) {
            rowEntry.push_back(std::stoi(num));
        }
        
        
        parsedCoordinates.push_back(
            Point(
                rowEntry[0],
                rowEntry[1],
                rowEntry[2]
            )
        );
    }
    
    // Calculate
    for (int i = 0; i < parsedCoordinates.size(); ++i) {
        Point point = parsedCoordinates[i];
        
        for (int k = i; k < parsedCoordinates.size(); ++k) {
            if (i == k) {
                continue;
            }
            
            result.push_back(
                DistanceBetweenTwoPoints(
                    point,
                    parsedCoordinates[k],
                    i,
                    k
                )
            );
        }
    }
    
    return result;
}

bool customSortDistances(const DistanceBetweenTwoPoints& a, const DistanceBetweenTwoPoints& b) {
    return a.distance < b.distance;
}

int main()
{
    std::string input; 
    std::ifstream file("input_day_8.txt");
    if (!file) {
        std::cout << "Could not open file\n";
        return 1;
    }
    
    std::vector<std::string> inputLines;
    std::string line;
    while (getline(file, line)) {
        inputLines.push_back(line);
    }
    
    auto pointDistances = parseAndCalculatePointDistances(inputLines);
    std::sort(pointDistances.begin(), pointDistances.end(), customSortDistances);
    
    std::unordered_map<int, std::vector<std::pair<int,long long>>> pointGraph;
    
    for (int i = 0; i < 1000; ++i) {
        pointGraph[pointDistances[i].a_id].push_back({pointDistances[i].b_id, pointDistances[i].distance});
        pointGraph[pointDistances[i].b_id].push_back({pointDistances[i].a_id, pointDistances[i].distance});
    }
    
    std::vector<int> connectedComponentSizes;
    std::unordered_set<int> seenPoints;
    
    for (auto& entry : pointGraph) {
        std::stack<int> dfs;
        dfs.push(entry.first);
        int connectedComponentSize = 0;
        
        if (seenPoints.count(entry.first)) continue;
        
        while (!dfs.empty()) {
            int node = dfs.top();
            dfs.pop();
            
            if (seenPoints.find(node) != seenPoints.end()) {
                continue;
            }
            
            seenPoints.insert(node);
            connectedComponentSize++;
            
            for (auto& neighbor_pair : pointGraph[node]) {
                int neighbor = neighbor_pair.first;
                if (!seenPoints.count(neighbor)) dfs.push(neighbor);
            }
        }
        
        connectedComponentSizes.push_back(connectedComponentSize);
    }
    
    std::sort(connectedComponentSizes.begin(), connectedComponentSizes.end());
    
    int end = connectedComponentSizes.size() - 1;
    int result = connectedComponentSizes[end] * connectedComponentSizes[end - 1] * connectedComponentSizes[end-2];
    std::cout << result << std::endl;
    return 0;
}
