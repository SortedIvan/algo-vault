class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        if (asteroids.size() == 0) {
            return vector<int>();
        }

        if (asteroids.size() == 1) {
            return asteroids;
        }
        
        stack<int> collisions;
        int pointer = 0;
        int currAsteroid = asteroids[0];
        bool exploded = false;

        while (pointer < asteroids.size()) {
            currAsteroid = asteroids[pointer];
            exploded = false;

            while (!collisions.empty() && currAsteroid < 0 && collisions.top() > 0) {
                if (std::abs(currAsteroid) > collisions.top()) {
                    collisions.pop();
                } else if (std::abs(currAsteroid) < collisions.top()) {
                    exploded = true;
                    break;
                } else {
                    collisions.pop();
                    exploded = true; 
                    break;
                }
            }

            if (!exploded) {
                collisions.push(currAsteroid);
            }

            pointer++;
        }
        
        vector<int> result;

        while (!collisions.empty()) {
            result.push_back(collisions.top());
            collisions.pop();
        }

        int left = 0;
        int right = result.size() - 1;

        while (left < right) {
            int temp = result[left];
            result[left] = result[right];
            result[right] = temp;
            left++;
            right--;
        }

        return result;
    }
};
