typedef long long LL;

class Solution {
public:
    int n;
    map<LL,int> mp;
    int leastBricks(vector<vector<int>>& ar) {
        n = ar.size();
        for( int i = 0 ; i < n ; i++ ) {
            int sz = ar[i].size();
            LL sum = 0;
            for( int j = 0 ; j < sz ; j++ ) {
                sum += ar[i][j];
                if(j < sz-1)
                    mp[sum]++;
            }
        }
        int mx = 0;
        for(auto it : mp)
            mx = max(mx,it.second);
        return n-mx;
    }
};