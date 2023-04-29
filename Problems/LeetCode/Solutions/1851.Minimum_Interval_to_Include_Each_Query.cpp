#define fi first
#define se second
#define pb push_back
typedef pair<int,int> pi;

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = intervals.size();
        int m = queries.size();
        vector<pi> q;
        for( int i = 0 ; i < m ; i++ )
            q.pb(pi(queries[i],i));
        set<pi> s;
        vector<int> ans(m);
        sort(q.begin(),q.end());
        sort(intervals.begin(),intervals.end());
        for( int i = 0 , id = 0 ; i < m ; i++ ) {
            int lim = q[i].fi;
            int qid = q[i].se;
            while(id < n && intervals[id][0] <= lim)
                s.insert( pi( intervals[id][1]-intervals[id][0]+1 , id++ ) );
            while(!s.empty() && intervals[s.begin()->se][1] < lim)
                s.erase(s.begin());
            ans[qid] = (s.empty()) ? -1 : s.begin()->fi;
        }
        return ans;
    }
};