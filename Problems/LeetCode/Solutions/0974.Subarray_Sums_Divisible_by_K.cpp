class Solution {
public:
    int subarraysDivByK(vector<int>& ar, int k) {
        int n = ar.size() , ans = 0;
        vector<int> cnt(k,0);
        cnt[0] = 1;
        for( int i = 0 , sum = 0 ; i < n ; i++ ) {
            sum += ar[i];
            if(sum >= 0)
                sum %= k;
            else
                sum = (k - abs(sum) % k) % k;
            ans += cnt[sum]++;
        }
        return ans;
    }
};