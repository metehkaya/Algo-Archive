typedef long long LL;

class Solution {
public:
    const int mod = (int) 1e9+7;
    int getrev(int val) {
        int revval = 0;
        while(val) {
            int d = val%10;
            val /= 10;
            revval = 10*revval + d;
        }
        return revval;
    }
    int countNicePairs(vector<int>& ar) {
        int n = ar.size();
        map<int,int> cnt;
        for( int i = 0 ; i < n ; i++ ) {
            int val = ar[i];
            int revval = getrev(val);
            cnt[val-revval]++;
        }
        LL ans = 0;
        for(auto it : cnt) {
            LL f = it.second;
            ans += f*(f-1)/2;
        }
        return ans % mod;
    }
};