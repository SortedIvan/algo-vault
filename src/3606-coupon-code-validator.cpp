class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        std::unordered_map<string, std::vector<std::string>> businessLineCouponMap = {
            {"electronics", std::vector<std::string>()},
            {"grocery", std::vector<std::string>()},
            {"pharmacy", std::vector<std::string>()},
            {"restaurant", std::vector<std::string>()},
        };

        const std::vector<std::string> orderOfBusinessLines = {
            "electronics", "grocery", "pharmacy", "restaurant"
        };

        for (int i = 0; i < code.size(); ++i) {

            // first, validate if its even active
            if (!isActive[i]) {continue;}

            const std::string codeElement = code[i];
            const std::string businessLineElement = businessLine[i];

            if (codeElement.empty() || businessLineElement.empty()) {
                continue;
            }

            if (!validateCodeIsValid(codeElement)) {continue;}
            if (businessLineCouponMap.find(businessLineElement) == businessLineCouponMap.end()){
                continue;
            }

            businessLineCouponMap[businessLineElement].push_back(codeElement);
        }

        std::vector<std::string> result; 

        for (const std::string& line : orderOfBusinessLines) {
            std::sort(businessLineCouponMap[line].begin(), 
                businessLineCouponMap[line].end());

            for (int k = 0; k < businessLineCouponMap[line].size(); ++k) {
                result.push_back(businessLineCouponMap[line][k]);
            }
        };

        return result;
    }

    static bool validateCodeIsValid(const std::string& code) {
        for (int i = 0; i < code.size(); ++i) {
            // 97 - 122 // a-z
            // 95 // _
            // 65 - 90 // A-Z
            // 48 - 57 // 0-9
            const char c = code[i];
            bool charValid = (c >= 97 && c <= 122) ||
                c == 95 ||
                (c >= 65 && c <= 90) ||
                (c >= 48 && c <= 57);

            if (!charValid) {
                return false;
            }
        }

        return true;
    }
};
