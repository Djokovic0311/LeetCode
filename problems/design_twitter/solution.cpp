class Twitter {
public:
    set<pair<int, pair<int, int>>, greater<pair<int, pair<int, int>>>> s;
    map<int, unordered_set<int>> mp;
    int countOfPost;

    Twitter() {
        countOfPost = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        pair<int, pair<int, int>> p = {countOfPost, {userId, tweetId}};
        s.insert(p);
        countOfPost++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        unordered_set<int> st = mp[userId];

        set<pair<int, pair<int, int>>, greater<pair<int, pair<int, int>>>>::iterator it;
        it = s.begin();
        
        while(res.size() != 10 && it != s.end()){
            pair<int, pair<int, int>> p = *it;
            if(st.count(p.second.first) == 1 || p.second.first == userId)
                res.push_back(p.second.second);
            it++;
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        mp[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        mp[followerId].erase(followeeId);
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