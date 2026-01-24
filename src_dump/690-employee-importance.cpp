/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, vector<int>> nodeMap;
        unordered_map<int, int> employeeMap;

        for (int i = 0; i < employees.size(); ++i) {
            employeeMap[employees[i]->id] = employees[i]->importance;
            nodeMap[employees[i]->id] = employees[i]->subordinates;
        }

        if (employees.empty()) {
            return 0;
        }

        if (employees.size() == 1) {
            return employees[0]->importance;
        }

        return findTotalImportance(employeeMap, nodeMap, id);
    }

    int findTotalImportance(unordered_map<int, int>& employeeMap, unordered_map<int,vector<int>>& nodeMap, int id) {
        queue<int> bfs;
        bfs.push(id);
        int totalImportance = 0;
        while (!bfs.empty()) {
            int employee = bfs.front();
            bfs.pop();
            totalImportance += employeeMap[employee];

            for (int i = 0; i < nodeMap[employee].size(); ++i) {
                bfs.push(nodeMap[employee][i]);
            }
        }

        return totalImportance;
    } 
};
