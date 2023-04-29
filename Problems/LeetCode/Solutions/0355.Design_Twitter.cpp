#define fi first
#define se second
typedef pair<int,int> pi;
typedef pair<int,pi> pii;

class Twitter {
public:
    int n;
    int n_tweets[501];
    set<int> follows[501];
    vector<pi> tweets[501];
    Twitter() {
        n = 0;
        memset(n_tweets,0,sizeof(n_tweets));
    }
    void postTweet(int userId, int tweetId) {
        n_tweets[userId]++;
        tweets[userId].push_back(pi(tweetId,n++));
    }
    vector<int> getNewsFeed(int userId) {
        priority_queue<pii> heap;
        vector<int> v(follows[userId].begin(),follows[userId].end());
        v.push_back(userId);
        int sz = v.size();
        for( int i = 0 ; i < sz ; i++ ) {
            int id = v[i];
            int id_t = n_tweets[id];
            if(id_t)
                heap.push(pii(tweets[id][id_t-1].se,pi(id,id_t-1)));
        }
        int rem = 10;
        vector<int> ans;
        while(rem && !heap.empty()) {
            rem--;
            pii p = heap.top();
            heap.pop();
            int id = p.se.fi;
            int id_t = p.se.se;
            ans.push_back(tweets[id][id_t].fi);
            if(id_t)
                heap.push(pii(tweets[id][id_t-1].se,pi(id,id_t-1)));
        }
        return ans;
    }
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};