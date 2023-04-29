class Solution {
public:
    int largestCombination(vector<int>& ar) {
        int ans = 0;
        int n = ar.size();
        vector<int> cnt(30,0);
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < 30 ; j++ )
                if(ar[i] & (1<<j))
                    cnt[j]++;
        for( int i = 0 ; i < 30 ; i++ )
            ans = max(ans,cnt[i]);
        return ans;
    }
};
