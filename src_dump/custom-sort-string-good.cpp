#include <map>

class Solution {
public:
    string customSortString(string order, string s) {
        std::map<char, int> characters;
        std::string result = "";
        int pointer = 0;

        for (int i = 0; i < s.size(); i++) {
            // if we find the key
            if (characters.find(s[i]) != characters.end()) {
                characters[s[i]] = characters[s[i]]  + 1;
            }
            else {
                characters.insert({s[i], 1});
            }
        }

        for (int i = 0; i < order.size(); i++) {
            int amount = 0;

            if (characters.find(order[i]) != characters.end()){
                amount = characters[order[i]];
            }

            result.append(amount,order[i]);

            if (amount > 0) {
                characters.erase(order[i]);
            }
        }

        // For the rest of the left over characters in s, simply put them in result
        for (auto i = characters.begin(); i != characters.end(); i++){
            result.append(i->second, i->first);            
        }
        
        return result;
    }
};
