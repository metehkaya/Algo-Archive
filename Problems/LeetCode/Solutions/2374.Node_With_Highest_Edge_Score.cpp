class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long> sum(n,0);
        for( int i = 0 ; i < n ; i++ )
            sum[edges[i]] += i;
        int ans = 0;
        for( int i = 1 ; i < n ; i++ )
            if(sum[i] > sum[ans])
                ans = i;
        return ans;
    }
};
