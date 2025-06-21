class Solution {
public:
    int numSub(string s) {
        unordered_map<int, int> substringCount;
        vector<string> substrings = splitString(s, '0');
        long long numberSum = 0;

        for (int i = 0; i < substrings.size(); ++i) {
            substringCount[substrings[i].size()]++;
        }

        for (auto pair : substringCount) {
            numberSum += (pair.second * countSubstrings(pair.first));
        }

        return numberSum % 1000000007;;
    }

    long countSubstrings(long size) {
        return (size * (size + 1)) / 2;
    }

    vector<string> splitString(string& input, char delimiter)
    {
        istringstream stream(input);
        vector<string> tokens;
        string token;

        while (getline(stream, token, delimiter)) {
            if (!token.empty()) {
                tokens.push_back(token);
            }
        }

        return tokens;
    }
};
