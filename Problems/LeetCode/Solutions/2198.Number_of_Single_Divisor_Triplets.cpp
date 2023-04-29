typedef long long LL;

class Solution {
public:
    LL singleDivisorTriplet(vector<int>& nums) {
        vector<LL> cnt(101,0);
        for(int x : nums)
            cnt[x]++;
        LL ans = 0;
        for( int i = 1 ; i <= 100 ; i++ )
            if(cnt[i])
                for( int j = i ; j <= 100 ; j++ )
                    if(cnt[j])
                    for( int k = j ; k <= 100 ; k++ )
                        if(cnt[k]) {
                            int sum = (i+j+k);
                            int cnt_div = 0;
                            cnt_div += ((sum % i) == 0);
                            cnt_div += ((sum % j) == 0);
                            cnt_div += ((sum % k) == 0);
                            if(cnt_div == 1) {
                                LL cnt_i = cnt[i];
                                LL cnt_j = cnt[j];
                                LL cnt_k = cnt[k];
                                if(i < j and j < k)
                                    ans += cnt_i*cnt_j*cnt_k;
                                else if(i == j)
                                    ans += cnt_j*(cnt_j-1)/2*cnt_k;
                                else
                                    ans += cnt_j*(cnt_j-1)/2*cnt_i;
                            }
                        }
        return 6*ans;
    }
};
