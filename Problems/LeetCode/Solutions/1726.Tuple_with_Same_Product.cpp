class Solution {
public:
    int tupleSameProduct(vector<int>& ar) {
        int ans = 0;
        int n = ar.size();
        map<int,int> cnt;
        for( int i = 0 ; i < n ; i++ )
            for( int j = i+1 ; j < n ; j++ ) {
                int sum = ar[i]*ar[j];
                ans += cnt[sum];
                cnt[sum]++;
            }
        return 8*ans;
    }
};
