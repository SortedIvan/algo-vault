class Solution {
public:
    bool judgeCircle(string moves) {
        std::pair<int,int> curr_position = {0,0};

        for (int i = 0; i < moves.size(); ++i) {
            applyMove(moves[i], curr_position);
        }

        if (curr_position.first == 0 && curr_position.second == 0) {
            return true;
        }

        return false;
    }

    void applyMove(const char move, std::pair<int,int>& curr_position) {
        switch (move) {
            case 'U':
                curr_position.second += 1;
                break;
            case 'D':
                curr_position.second -= 1;
                break;
            case 'L':
                curr_position.first -= 1;
                break;
            case 'R':
                curr_position.first += 1;
                break;
        }
    }
};
