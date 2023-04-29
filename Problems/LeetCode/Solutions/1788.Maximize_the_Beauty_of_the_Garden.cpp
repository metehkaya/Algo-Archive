class Solution {
public:
    static const int maxs = 10000;
    int start[2*maxs+1];
    int finish[2*maxs+1];
    int maximumBeauty(vector<int>& v) {
        memset(start,-1,sizeof(start));
        memset(finish,-1,sizeof(finish));
        int n = v.size();
        vector<int> sum({0});
        for( int i = 0 ; i < n ; i++ ) {
            int x = v[i];
            sum.push_back(sum.back()+max(x,0));
            if(start[x+maxs] == -1)
                start[x+maxs] = i;
            finish[x+maxs] = i;
        }
        int ans = INT_MIN;
        for( int i = 0 ; i <= 2*maxs ; i++ )
            if(start[i] != finish[i])
                ans = max(ans,2*(i-maxs)+sum[finish[i]]-sum[start[i]+1]);
        return ans;
    }
};
