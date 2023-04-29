#define fi first
#define se second
#define pb push_back
typedef pair<int,int> pi;
typedef pair<int,pi> pii;

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int p) {
        vector<vector<pi>> meets(n);
        priority_queue<pii,vector<pii>,greater<pii>> heap;
        for( int i = 0 ; i < meetings.size() ; i++ ) {
            int u = meetings[i][0];
            int v = meetings[i][1];
            int t = meetings[i][2];
            meets[u].pb(pi(v,t));
            meets[v].pb(pi(u,t));
        }
        vector<bool> mark(n,false);
        mark[0] = mark[p] = true;
        for( int i = 0 ; i < meets[0].size() ; i++ )
            heap.push(pii(meets[0][i].se,pi(0,meets[0][i].fi)));
        for( int i = 0 ; i < meets[p].size() ; i++ )
            heap.push(pii(meets[p][i].se,pi(p,meets[p][i].fi)));
        while(!heap.empty()) {
            pii temp = heap.top();
            heap.pop();
            int t = temp.fi;
            int u = temp.se.fi;
            int v = temp.se.se;
            if(!mark[u]) {
                mark[u] = true;
                for( int i = 0 ; i < meets[u].size() ; i++ )
                    if(meets[u][i].se >= t)
                        heap.push(pii(meets[u][i].se,pi(u,meets[u][i].fi)));
            }
            if(!mark[v]) {
                mark[v] = true;
                for( int i = 0 ; i < meets[v].size() ; i++ )
                    if(meets[v][i].se >= t)
                        heap.push(pii(meets[v][i].se,pi(v,meets[v][i].fi)));
            }
        }
        vector<int> ans;
        for( int i = 0 ; i < n ; i++ )
            if(mark[i])
                ans.pb(i);
        return ans;
    }
};
