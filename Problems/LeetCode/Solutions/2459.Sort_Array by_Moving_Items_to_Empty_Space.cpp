class Solution {
public:
    int n;
    int f(vector<int>& v, int idx_add) {
        int ans = 0;
        vector<int> dp(n,-1);
        vector<int> mark(n,0);
        for( int i = 0 ; i < n ; i++ )
            if(!mark[i]) {
                vector<int> nodes;
                int idx = i;
                while(!mark[idx]) {
                    mark[idx] = 1;
                    nodes.push_back(idx);
                    if(v[idx] == 0)
                        break;
                    idx = v[idx] + idx_add;
                }
                if(mark[idx] == 2)
                    dp[i] = dp[idx] + (int) nodes.size();
                else if(v[idx] == 0)
                    dp[i] = (int) nodes.size() - 1;
                else if(mark[idx] == 1 and nodes.size() > 1)
                    ans += (int) nodes.size() + 1;
                for(int u : nodes)
                    mark[u] = 2;
            }
        auto it = max_element(dp.begin(), dp.end());
        ans += (*it);
        return ans;
    }
    int sortArray(vector<int>& v) {
        n = v.size();
        return min(f(v,0),f(v,-1));
    }
};
