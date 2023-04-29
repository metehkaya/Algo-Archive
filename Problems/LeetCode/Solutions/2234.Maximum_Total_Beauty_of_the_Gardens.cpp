typedef long long LL;

class Solution {
public:
    long long maximumBeauty(vector<int>& ar, long long k, int t, int f, int p) {
        int n = ar.size();
        sort(ar.begin(),ar.end());
        for( int i = 0 ; i < n ; i++ )
            ar[i] = min(ar[i],t);
        vector<LL> sum(n+1,0);
        for( int i = 0 ; i < n ; i++ )
            sum[i+1] = sum[i]+ar[i];
        LL ans = 0;
        for( int i = 0 , j = 0 ; i <= n ; i++ ) {
            LL must = (LL) (n-i)*t - (sum[n]-sum[i]);
            if(must <= k) {
                LL rem = k-must;
                while(j < i && rem >= (LL)ar[j]*j-sum[j])
                    j++;
                LL score = (LL)f*(n-i);
                if(j > 0)
                    score += (LL)p * min((LL)t-1,(sum[j]+rem)/j);
                ans = max(ans,score);
            }
            if(i < n && ar[i] == t)
                break;
        }
        return ans;
    }
};
