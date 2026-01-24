
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        std::unordered_map<string, string> emailToNameMap;        
        std::unordered_map<string, vector<string>> accountToOtherAccountsMap;
        vector<vector<string>> result;

        // Build graph
        for (vector<string>& accs : accounts) {
            string accName = accs[0];

            if (accs.size() == 2) {
                emailToNameMap[accs[1]] = accName;
                
                if (accountToOtherAccountsMap.find(accs[1]) == accountToOtherAccountsMap.end()) {
                    accountToOtherAccountsMap.insert({accs[1], {}});
                }

                continue;
            }
            
            for (int i = 1; i < accs.size() - 1; ++i) {

                emailToNameMap[accs[i]] = accName;
                emailToNameMap[accs[i+1]] = accName;


                accountToOtherAccountsMap[accs[i]].push_back(accs[i+1]);
                accountToOtherAccountsMap[accs[i+1]].push_back(accs[i]);
            }
        }

        unordered_set<string> processed;

        for (auto const& x : emailToNameMap) {
            string accountEmail = x.first;
            string accountName = x.second;

            if (processed.find(accountEmail) != processed.end()) {
                continue;
            }

            processed.insert(accountEmail);

            vector<string> entry;
            entry.push_back(accountName);

            if (!accountToOtherAccountsMap[accountEmail].empty()) {
                entry.push_back(accountEmail);
                findAllConnectedEmails(processed, accountEmail, entry, accountToOtherAccountsMap);
            } else {
                entry.push_back(accountEmail);
            }

            sort(entry.begin() + 1, entry.end());
            result.push_back(entry);
        }

        return result;
    }

    void findAllConnectedEmails(unordered_set<string>& processed, string currEmail, vector<string>& entry, std::unordered_map<string, vector<string>>& accountToOtherAccountsMap) {
        for (int i = 0; i < accountToOtherAccountsMap[currEmail].size(); ++i) {
            string otherEntryEmail = accountToOtherAccountsMap[currEmail][i];

            if (processed.find(otherEntryEmail) != processed.end()) {
                continue;
            }

            processed.insert(otherEntryEmail);
            entry.push_back(otherEntryEmail);

            findAllConnectedEmails(processed, otherEntryEmail, entry, accountToOtherAccountsMap);
        }
    }
};
