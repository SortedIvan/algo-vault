class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fivers = 0;
        int tens = 0;

        for (int i = 0; i < bills.size(); ++i) {
            if (bills[i] == 5) {
                fivers++;
            } else if (bills[i] == 10) {
                if (fivers == 0) {
                    return false;
                } else {
                    tens++;
                    fivers--;
                }
            } else if (bills[i] == 20) {
                if (tens == 0) {
                    if (fivers < 3) {
                        return false;
                    }

                    fivers -= 3;
                    continue;
                }

                if (fivers == 0) {
                    return false;
                }

                fivers--;
                tens--;
            }
        }

        return true;
    }
};
