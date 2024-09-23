class Twitter {
public:
    unordered_map <int, unordered_set<int>> followers;
    unordered_map <int, vector<vector<int>>> feeds;
    int count = 0;

public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        feeds[userId].push_back({count, tweetId});
        count += 1;
    }
    
    vector<int> getNewsFeed(int userId) {
        followers[userId].insert(userId);
        priority_queue <vector<int>> pq;
        for(int i: followers[userId]){
            if(feeds.contains(i)){
                int index = feeds[i].size() - 1;
                pq.push({feeds[i][index][0], feeds[i][index][1], index - 1, i});
            }
        }
        vector<int> result;
        while (pq.size()> 0 && result.size() < 10){
            vector<int> temp = pq.top();
            result.push_back(temp[1]);
            if (temp[2] >= 0) pq.push({feeds[temp[3]][temp[2]][0], feeds[temp[3]][temp[2]][1], temp[2] - 1, temp[3]});
            pq.pop();
        }
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followers[followerId].contains(followeeId)){
            followers[followerId].erase(followeeId);
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