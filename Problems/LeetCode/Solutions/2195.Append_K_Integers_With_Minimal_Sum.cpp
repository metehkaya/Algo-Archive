typedef long long LL;

class Solution {
public:
    long long minimalKSum(vector<int>& ar, int k) {
        LL ans = 0;
        ar.push_back(0);
        int n = ar.size();
        sort(ar.begin(),ar.end());
        for( int i = 1 ; i < n && k > 0 ; i++ )
            if(ar[i] > ar[i-1]+1) {
                int len = ar[i]-ar[i-1]-1;
                len = min(len,k);
                k -= len;
                LL s = ar[i-1]+1;
                LL e = ar[i-1]+len;
                ans += (s+e)*len/2;
            }
        if(k) {
            int len = k;
            LL s = ar[n-1]+1;
            LL e = ar[n-1]+len;
            ans += (s+e)*len/2;
        }
        return ans;
    }
};
