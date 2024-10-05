struct User {
    int userId;
    vector<int> followedBy;
    vector<int> follows;
    deque<int> userFeed; // holds the index of the tweet within the tweets vector

    User(int userId) {
        this->userId = userId;
    }
};

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
    unordered_map<int, int> userMap; // maps user id to index
    vector<User> users;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        if (userMap.find(userId) == userMap.end()) {
            users.push_back(User(userId));
            userMap.insert({userId, users.size() - 1});
        }

        // Create tweet
        Tweet tweet(tweetId, userId);
        tweets.push_back(tweet);
        int tweetIndex = tweets.size() - 1;
        int userIndex = userMap[userId];

        // Fix poster's newsfeed
        users[userIndex].userFeed.push_front(tweetIndex);
        users[userIndex].userFeed.pop_back();

        // Propagate tweet post over all followers
        for (int i = 0; i <  users[userIndex].followedBy.size(); ++i) {
            users[userMap[users[userIndex].followedBy[i]]].userFeed.push_front(tweetIndex);
            users[userMap[users[userIndex].followedBy[i]]].userFeed.pop_back();
        }
    }
    
    vector<int> getNewsFeed(int userId) {
        int userIndex = userMap[userId];
        vector<int> tweetIds;
        int tweetCounter = 0;
        deque<int> newsfeed = users[userIndex].userFeed;

        while (!newsfeed.empty() && tweetCounter < 10) {
            tweetCounter++;
            int tweetIndex = newsfeed.front();
            newsfeed.pop_front();
            tweetIds.push_back(tweets[tweetIndex].tweetId);
        }

        return tweetIds;
    }
    
    void follow(int followerId, int followeeId) {
        if (userMap.find(followerId) == userMap.end()) {
            users.push_back(User(followerId));
            userMap.insert({followerId, users.size() - 1});
        }

        if (userMap.find(followeeId) == userMap.end()) {
            users.push_back(User(followeeId));
            userMap.insert({followeeId, users.size() - 1});
        }

        int followerIndex = userMap[followerId];
        int followeeIndex = userMap[followeeId];

        users[followerIndex].followedBy.push_back(followeeIndex);
        users[followeeIndex].follows.push_back(followerIndex);
    }
    
    void unfollow(int followerId, int followeeId) {
        int followerIndex = userMap[followerId];
        int followeeIndex = userMap[followeeId];

        for (int i = 0; i < users[followerIndex].follows.size(); ++i) {
            if (users[followerIndex].follows[i] == followeeId) {
                users[followerIndex].follows
                .erase(users[followerIndex].follows.begin() + i);
                break;
            }
        }

        for (int i = 0; i < users[followeeIndex].followedBy.size(); ++i) {
            if (users[followeeIndex].followedBy[i] == followerId) {
                users[followeeIndex].followedBy
                .erase(users[followeeIndex].followedBy.begin() + i);
                break;
            }
        }
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
