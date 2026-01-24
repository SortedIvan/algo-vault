class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        
        if (seats.size() != students.size()) {
            return 0;
        }

        std::sort(seats.begin(), seats.end());
        std::sort(students.begin(), students.end());

        int amount = 0;

        for (int i = 0; i < seats.size(); i++) {
            amount += std::abs(seats[i] - students[i]);
        }

        return amount;
    }
};
