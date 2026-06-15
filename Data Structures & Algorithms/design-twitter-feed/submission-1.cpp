class Tweet {
public:
    int userId;
    int tweetId;
    int time;
    Tweet* next;

    Tweet(int uid, int tid, int t) {
        userId = uid;
        tweetId = tid;
        time = t;
        next = nullptr;
    }
};

class Compare {
public:
    bool operator()(Tweet* a, Tweet* b) {
        return a -> time < b -> time;
    }
};

class Twitter {
public:
    unordered_map<int, Tweet*> userTweets;
    unordered_map<int, vector<int>> follows;
    int time;

    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        if (userTweets.find(userId) == userTweets.end()) {
            Tweet* t = new Tweet(userId, tweetId, time + 1);
            userTweets[userId] = t;
        }
        else {
            Tweet* head = userTweets[userId];
            Tweet* t = new Tweet(userId, tweetId, time + 1);
            t -> next = head;
            userTweets[userId] = t;
        }
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> f;
        if (follows.find(userId) != follows.end()) f = follows[userId];
        f.push_back(userId);

        priority_queue<Tweet*, vector<Tweet*>, Compare> pq;
        for (int i = 0; i < f.size(); i++) {
            if (userTweets.find(f[i]) != userTweets.end()) pq.push(userTweets[f[i]]);
        }

        vector<int> feed;
        while (!pq.empty() && feed.size() < 10) {
            Tweet* t = pq.top();
            pq.pop();
            feed.push_back(t -> tweetId);
            t = t -> next;
            if (t) pq.push(t);
        }

        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        if (find(follows[followerId].begin(), follows[followerId].end(), followeeId) != follows[followerId].end()) return;
        follows[followerId].push_back(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (follows.find(followerId) == follows.end()) return;
        if (find(follows[followerId].begin(), follows[followerId].end(), followeeId) == follows[followerId].end()) return;
        follows[followerId].erase(find(follows[followerId].begin(), follows[followerId].end(), followeeId));
    }
};