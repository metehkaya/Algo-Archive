#define fi first
#define se second
#define pb push_back
typedef long long LL;
typedef pair<int,int> pi;
typedef pair<pi,int> pii;

struct st1 {
    bool operator()(const pii &x , const pii &y) {
        return x.fi.fi > y.fi.fi;
    }
};

struct st2 {
    bool operator()(const pii &x , const pii &y) {
        if(x.fi.se != y.fi.se)
            return x.fi.se > y.fi.se;
        return x.se > y.se;
    }
};

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& ar) {
        LL t = 0;
        int n = ar.size();
        priority_queue<pii, vector<pii>, st1> todo;
        priority_queue<pii, vector<pii>, st2> avail;
        for( int i = 0 ; i < n ; i++ )
            todo.push( pii( pi( ar[i][0] , ar[i][1] ) , i ) );
        int rem = n;
        vector<int> ans;
        while(rem--) {
            while(!todo.empty() && t >= todo.top().fi.fi) {
                pii p = todo.top();
                todo.pop();
                avail.push(p);
            }
            if(avail.empty()) {
                t = todo.top().fi.fi;
                while(!todo.empty() && t >= todo.top().fi.fi) {
                    pii p = todo.top();
                    todo.pop();
                    avail.push(p);
                }
            }
            pii p = avail.top();
            avail.pop();
            t += p.fi.se;
            ans.pb(p.se);
        }
        return ans;
    }
};