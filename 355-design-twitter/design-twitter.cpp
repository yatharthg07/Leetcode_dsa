class Twitter {
public:
    unordered_map<int,vector<pair<int,int>>> twts;
    unordered_map<int,unordered_set<int>> follows;
    int n=0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        n+=1;
        follows[userId].insert(userId);
        twts[userId].push_back({n,tweetId});
        
        
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto it:follows[userId])
        {
            for(auto twt:twts[it])
            {
                pq.push(twt);
                if(pq.size()>10)
                {
                    pq.pop();
                }
            }
        }
        vector<int> ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);

        
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
        
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