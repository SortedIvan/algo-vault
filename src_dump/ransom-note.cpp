class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> characters;
        
        for (int i = 0; i < magazine.size(); i++)
        {
            if (characters.find(magazine[i]) != characters.end())
            {
                characters[magazine[i]] += 1;
            }
            else
            {
                characters.insert({magazine[i], 1});
            }
        }

        for (int i = 0; i < ransomNote.size(); i++)
        {
            if (characters.find(ransomNote[i]) != characters.end())
            {
                if (characters[ransomNote[i]] == 0)
                {
                    return false;
                }
                else
                {
                    characters[ransomNote[i]]--;
                }
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};
