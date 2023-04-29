class Solution {
public:
    vector<int> numberOfPairs(vector<int>& ar) {
        int n = ar.size();
        vector<int> cnt(101,0);
        for( int i = 0 ; i < n ; i++ )
            cnt[ar[i]]++;
        int total = 0;
        for( int i = 0 ; i < 101 ; i++ )
            total += cnt[i]/2;
        vector<int> ans({total,n-2*total});
        return ans;
    }
};
