class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<int> operations = {3,5};
        map<int, string> map = {{3, "Fizz"}, {5, "Buzz"}};
        vector<string> result; 

        for (int i = 1; i < n + 1; ++i) {
            string res = ""; 
            for (int operation : operations) {
                if (i % operation == 0) {
                    res += map[operation];
                }
            }

            if (res.empty()) {
                res += std::to_string(i);
            }
            result.push_back(res);

        }
        return result;
    }
};
