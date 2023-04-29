#define fi first
#define se second
typedef pair<int,int> pi;

class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        vector<vector<pi>> adj(n);
        for(auto e : edges) {
            if(vals[e[1]] > 0)
                adj[e[0]].push_back(pi(vals[e[1]],e[1]));
            if(vals[e[0]] > 0)
                adj[e[1]].push_back(pi(vals[e[0]],e[0]));
        }
        int ans = INT_MIN;
        for( int i = 0 ; i < n ; i++ ) {
            int deg = adj[i].size() , sum = vals[i];
            sort(adj[i].begin(),adj[i].end());
            for( int j = deg-1 ; j >= 0 && j >= deg-k ; j-- )
                sum += adj[i][j].fi;
            ans = max(ans,sum);
        }
        return ans;
    }
};
