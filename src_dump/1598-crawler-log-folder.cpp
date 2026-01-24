class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<int> folders;
        int folderCounter = 0;

        for (int i = 0; i < logs.size(); i++) {
            if (logs[i] == "../") {
                if (folders.size() > 0) {
                    folders.pop();
                }
            } else if (logs[i] == "./") {
                // do nothing
            } else {
                folders.push(folderCounter);
                folderCounter++;
            }  
        }

        return folders.size();
    }
};
