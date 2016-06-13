#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <list>

using namespace std;

class Twitter {
    typedef list<pair<int, int>>::iterator Iter;
    unordered_map<int, set<int>> followers;
    unordered_map<int, list<pair<int, int>>> twitters;
    int timestamp;
    struct PairLess : less<pair<Iter, Iter>> {
        bool operator() (const pair<Iter, Iter> &lhs, const pair<Iter, Iter> &rhs) {
            return lhs.first->second < rhs.first->second;
        }
    };
public:
    /** Initialize your data structure here. */
    Twitter() : timestamp(0) { }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        twitters[userId].push_front(make_pair(tweetId, timestamp++));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        followers[userId].insert(userId);
        priority_queue<pair<Iter, Iter>, vector<pair<Iter, Iter>>, PairLess> q;
        for (auto f : followers[userId]) {
            if (twitters[f].begin() != twitters[f].end())
                q.push(make_pair(twitters[f].begin(), twitters[f].end()));
        }
        int size = 0;
        vector<int> ret;
        while (!q.empty() && size < 10) {
            pair<Iter, Iter> p = q.top();
            q.pop();
            ret.push_back(p.first->first);
            if (++p.first != p.second)
                q.push(p);
            ++size;
        }
        return ret;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followers.find(followerId) == followers.end())
            return;
        followers[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
int main(void)
{
    Twitter twitter;

    // User 1 posts a new tweet (id = 5).
    twitter.postTweet(1, 5);

    // User 1's news feed should return a list with 1 tweet id -> [5].
    for (auto t : twitter.getNewsFeed(1))
        cout << t << " ";
    cout << endl;

    // User 1 follows user 2.
    twitter.follow(1, 2);

    // User 2 posts a new tweet (id = 6).
    twitter.postTweet(2, 6);

    // User 1's news feed should return a list with 2 tweet ids -> [6, 5].
    // Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
    for (auto t : twitter.getNewsFeed(1))
        cout << t << " ";
    cout << endl;

    // User 1 unfollows user 2.
    twitter.unfollow(1, 2);

    // User 1's news feed should return a list with 1 tweet id -> [5],
    // since user 1 is no longer following user 2.
    for (auto t : twitter.getNewsFeed(1))
        cout << t << " ";
    cout << endl;

    return 0;
}
