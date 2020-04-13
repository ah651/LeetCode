#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
#include <random>


struct Post {
    int tweetId;
    int userId;
    unsigned long long t = 0;
    Post(int _userId = -1, int _tweetId = -1, unsigned long long _t = 0) : tweetId(_tweetId), userId(_userId), t(_t) {}
    bool operator<(const Post & p) const {
        return t < p.t;
    }
};


struct Node {
    int userId;
    unordered_set<int> f;
    vector<Post> myTweets;
    Node(int _userId = -1) : userId(_userId) {
        f.clear();
        myTweets.clear();
    }
};

struct cmp {
    bool operator()(const pair<vector<Post>::reverse_iterator, vector<Post> *> & a, const pair<vector<Post>::reverse_iterator, vector<Post> *> & b) const {
        return *(a.first) < *(b.first);
    }
};

class Twitter {
public:
    /** Initialize your data structure here. */
    unordered_map<int, Node> users;
    unsigned long long t = 0;
    Twitter() {
        t = 0;
        users.clear();
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        t++;
        if (users.count(userId) == 0) {
            users[userId] = Node(userId);
        }
        Post p(userId, tweetId, t);
        users[userId].myTweets.push_back(p);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        int cnt = 0;
        vector<int> result; 
        //priority_queue<pair<const vector<Post>::iterator, const vector<Post> &>, vector<pair<const vector<Post>::iterator, const vector<Post> &>>, cmp> pq;
        priority_queue<pair<vector<Post>::reverse_iterator, vector<Post> *>, vector<pair<vector<Post>::reverse_iterator, vector<Post> *>>, cmp> pq;
        if (users[userId].myTweets.size()) {
            pq.push(make_pair(users[userId].myTweets.rbegin(), &(users[userId].myTweets)));
        } 
        for (auto i = users[userId].f.begin(); i != users[userId].f.end(); i++) {
            if (users[*i].myTweets.size()) {
                pq.push(make_pair(users[*i].myTweets.rbegin(), &(users[*i].myTweets)));
            }
        }
        while (!pq.empty() && cnt < 10) {
            auto tmp = pq.top(); pq.pop();
            cnt++;
            result.push_back(tmp.first->tweetId);
            auto i = tmp.first; i++;
            if (tmp.second->rend() != i) {
                pq.push(make_pair(i, tmp.second));
            }
        }

        return result;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        //if (!users.count(followeeId) || !users.count(followerId)) return;
        if (!users.count(followerId)) {
            users[followerId] = Node(followerId);
        }
        if (!users.count(followeeId)) {
            users[followeeId] = Node(followeeId);
        }
        users[followerId].f.insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (!users.count(followeeId) || !users.count(followerId)) return;
        if (users[followerId].f.count(followeeId)) {
            users[followerId].f.erase(followeeId);
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