/*
 * @lc app=leetcode id=355 lang=cpp
 *
 * [355] Design Twitter
 *
 * https://leetcode.com/problems/design-twitter/description/
 *
 * algorithms
 * Medium (27.62%)
 * Likes:    497
 * Dislikes: 142
 * Total Accepted:    35.8K
 * Total Submissions: 129.7K
 * Testcase Example:  '["Twitter","postTweet","getNewsFeed","follow","postTweet","getNewsFeed","unfollow","getNewsFeed"]\n[[],[1,5],[1],[1,2],[2,6],[1],[1,2],[1]]'
 *
 * Design a simplified version of Twitter where users can post tweets,
 * follow/unfollow another user and is able to see the 10 most recent tweets in
 * the user's news feed. Your design should support the following methods:
 * 
 * 
 * 
 * postTweet(userId, tweetId): Compose a new tweet.
 * getNewsFeed(userId): Retrieve the 10 most recent tweet ids in the user's
 * news feed. Each item in the news feed must be posted by users who the user
 * followed or by the user herself. Tweets must be ordered from most recent to
 * least recent.
 * follow(followerId, followeeId): Follower follows a followee.
 * unfollow(followerId, followeeId): Follower unfollows a followee.
 * 
 * 
 * 
 * Example:
 * 
 * Twitter twitter = new Twitter();
 * 
 * // User 1 posts a new tweet (id = 5).
 * twitter.postTweet(1, 5);
 * 
 * // User 1's news feed should return a list with 1 tweet id -> [5].
 * twitter.getNewsFeed(1);
 * 
 * // User 1 follows user 2.
 * twitter.follow(1, 2);
 * 
 * // User 2 posts a new tweet (id = 6).
 * twitter.postTweet(2, 6);
 * 
 * // User 1's news feed should return a list with 2 tweet ids -> [6, 5].
 * // Tweet id 6 should precede tweet id 5 because it is posted after tweet id
 * 5.
 * twitter.getNewsFeed(1);
 * 
 * // User 1 unfollows user 2.
 * twitter.unfollow(1, 2);
 * 
 * // User 1's news feed should return a list with 1 tweet id -> [5],
 * // since user 1 is no longer following user 2.
 * twitter.getNewsFeed(1);
 * 
 * 
 */
class Twitter {
public:
    unordered_map<int, unordered_set<int>> fmap;
    /** Initialize your data structure here. */
    vector<pair<int, int>> tvec;
    unordered_map<int, queue<int>> recent;
    unordered_map<int, int> lastidx;
    Twitter() {
        fmap.clear();
        tvec.clear();
        lastidx.clear();
        recent.clear();
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tvec.push_back(pair(userId, tweetId));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        int last = lastidx[userId]; 
        int imax = tvec.size();
        for(int i = last; i<imax; i++){
            if(fmap[userId].count(tvec[i].first)!=0 || tvec[i].first == userId){
                recent[userId].push(tvec[i].second);
                if((int)recent[userId].size() > 10)
                    recent[userId].pop();
            }
        }
        lastidx[userId] = imax;
        queue<int> tmp;
        vector<int> ans(recent[userId].size(), 0);
        int p = recent[userId].size()-1;
        while(!recent[userId].empty()){
            tmp.push(recent[userId].front());
            ans[p--] = recent[userId].front();
            recent[userId].pop();
        }
        recent[userId] = tmp;
        return ans;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        fmap[followerId].insert(followeeId);
        lastidx[followerId] = 0;
        queue<int> empty;
        swap(recent[followerId], empty);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        fmap[followerId].erase(followeeId);
        lastidx[followerId] = 0;
        queue<int> empty;
        swap(recent[followerId], empty);
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

