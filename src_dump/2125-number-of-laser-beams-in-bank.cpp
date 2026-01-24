class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        std::vector<int> securityDeviceCounter;
        int resultBeams = 0;

        if (bank.size() == 0 || bank.size() == 1) {
            return 0;
        }

        for (int i = 0; i < bank.size(); ++i) {
            int devicesOnCurrentRow = 0;
            for (int k = 0; k < bank[i].size(); ++k) {
                if (bank[i][k] == '1') {
                    devicesOnCurrentRow++;
                }
            }

            if (devicesOnCurrentRow > 0) {
                securityDeviceCounter.push_back(devicesOnCurrentRow);
            }
        }

        if (securityDeviceCounter.empty()) {
            return 0;
        }

        for (int i = 0; i < securityDeviceCounter.size() - 1; ++i) {
            resultBeams += securityDeviceCounter[i] * securityDeviceCounter[i+1];
        }

        return resultBeams;
    }
};
