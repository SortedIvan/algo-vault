class Solution {
public:
    bool isValid(string s) {
        std::stack<char> characters;
        for (const auto& c : s)
        {
            if (c == '(' || c == '[' || c == '{')
            {
                characters.push(c);
            }
            else
            {

                if (characters.empty())
                {
                    return false;
                }

                if (characters.top() == getReversedBracket(c))
                {
                    characters.pop();
                }
                else
                {
                    return false;
                }
            }

        }

        if (characters.empty())
        {
            return true;
        }

        return false;
    }

    char getReversedBracket(char bracket)
    {
        switch(bracket) {
            case ')':
            return '(';
            case ']':
            return '[';
            case '}':
            return '{';
        }

        return ' ';
    }
};
