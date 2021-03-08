class Solution {
public:
    int beautySum(string s) {
        int n = s.length() , ans = 0;
        for( int i = 0 ; i < n ; i++ ) {
            vector<int> cnt(26,0);
            for( int j = i ; j < n ; j++ ) {
                cnt[s[j]-'a']++;
                int minVal = INT_MAX , maxVal = 0;
                for( int k = 0 ; k < 26 ; k++ )
                    if(cnt[k]) {
                        minVal = min(minVal,cnt[k]);
                        maxVal = max(maxVal,cnt[k]);
                    }
                ans += maxVal - minVal;
            }
        }
        return ans;
    }
};