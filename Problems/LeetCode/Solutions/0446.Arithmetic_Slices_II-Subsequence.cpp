typedef long long LL;

class Solution {
public:
    map<LL,int> dp[1000];
    map<LL,int> dp2[1000];
    int numberOfArithmeticSlices(vector<int>& ar) {
        int n = ar.size() , ans = 0;
        map<LL,int>::iterator it;
        for( int i = 0 ; i < n ; i++ ) {
            for( int j = 0 ; j < i ; j++ ) {
                LL diff = (LL) ar[i] - ar[j];
                it = dp2[j].find(diff);
                if(it != dp2[j].end()) {
                    int add = it->second;
                    ans += add;
                    dp[i][diff] += add;
                }
                it = dp[j].find(diff);
                if(it != dp[j].end()) {
                    int add = it->second;
                    ans += add;
                    dp[i][diff] += add;
                }
                dp2[i][diff]++;
            }
        }
        return ans;
    }
};