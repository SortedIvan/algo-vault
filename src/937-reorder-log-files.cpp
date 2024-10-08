class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> letterLogs;
        vector<string> digitLogs;

        for (int i = 0; i < logs.size(); ++i) {
            int firstSpacePos = logs[i].find(' ');
            char firstCharAfterId = logs[i][firstSpacePos + 1];
            
            if (isdigit(firstCharAfterId)) {
                digitLogs.push_back(logs[i]);
            } else {
                letterLogs.push_back(logs[i]);
            }
        }

        sort(letterLogs.begin(), letterLogs.end(), [&](const string& log1, const string& log2) {
            string id1 = log1.substr(0, log1.find(' '));
            string id2 = log2.substr(0, log2.find(' '));
            string content1 = log1.substr(log1.find(' ') + 1);
            string content2 = log2.substr(log2.find(' ') + 1);
            
            if (content1 != content2) {
                return content1 < content2;
            }
            return id1 < id2;
        });

        letterLogs.insert(letterLogs.end(), digitLogs.begin(), digitLogs.end());

        return letterLogs;
    }
};
