struct Tweet {
    int tweetId;
    int userId;

    Tweet(int tweetId, int userId) {
        this->tweetId = tweetId;
        this->userId = userId;
    }
};

class Twitter {
private:
    vector<Tweet> tweets;
    unordered_map<int, unordered_set<int>> following;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets.push_back(Tweet(tweetId, userId));
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> newsfeed;
        for (int i = tweets.size() - 1; i >= 0; i--) {
            if (newsfeed.size() == 10) {
                break;
            }

            if (tweets[i].userId == userId || following[userId].find(tweets[i].userId) != following[userId].end()) {
                newsfeed.push_back(tweets[i].tweetId);
            }
        }

        return newsfeed;
    }
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) {
            return;
        }
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) {
            return;
        }

        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
