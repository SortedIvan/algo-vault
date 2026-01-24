#include <deque>

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        std::deque<int> queue;
        int sandwichPointer = 0;
        int studentsAte = 0;;
        int counter = 0;
        int remaining = students.size();

        for (int i = 0; i < students.size(); i++) {
            queue.push_back(students[i]);
        }

        while (sandwichPointer < sandwiches.size()) {
            if (counter >= remaining) {
                break;
            }
            
            if (queue.front() == sandwiches[sandwichPointer]) {
                queue.pop_front();
                sandwichPointer++;
                counter = 0;
                continue;
            }

            if (queue.front() != sandwiches[sandwichPointer]) {
                counter++;
                remaining = queue.size() - studentsAte;
                queue.push_back(queue.front());
                queue.pop_front();
                continue;            
            }
        }

        return queue.size();

    }
};
