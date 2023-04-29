#define fi first
#define se second
#define pb push_back
typedef long long LL;
typedef pair<LL,int> pi;

class Solution {
public:
    vector<int> assignTasks(vector<int>& w, vector<int>& tt) {
        int n = w.size();
        int m = tt.size();
        set<pi> idle;
        priority_queue<pi> pq;
        for( int i = 0 ; i < n ; i++ )
            idle.insert({w[i],i});
        LL t = 0;
        vector<int> ans;
        for( int i = 0 ; i < m ; i++ ) {
            t = max(t,(LL)i);
            while(!pq.empty() && -pq.top().fi <= t) {
                int id = pq.top().se;
                pq.pop();
                idle.insert({w[id],id});
            }
            if(idle.empty()) {
                t = -pq.top().fi;
                while(!pq.empty() && -pq.top().fi <= t) {
                    int id = pq.top().se;
                    pq.pop();
                    idle.insert({w[id],id});
                }
            }
            int id = (*idle.begin()).se;
            ans.pb(id);
            idle.erase(idle.begin());
            pq.push({-t-tt[i],id});
        }
        return ans;
    }
};