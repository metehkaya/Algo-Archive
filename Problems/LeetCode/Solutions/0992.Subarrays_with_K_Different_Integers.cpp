class Solution {
public:
    int solve(vector<int>& ar, int k) {
        if(k == 0)
            return 0;
        int n = ar.size() , res = 0 , dif = 0;
        vector<int> cnt(n+1,0);
        for( int i = 0 , j = 0 ; i < n ; i++ ) {
            if(i and --cnt[ar[i-1]] == 0)
                dif--;
            while(j < n and dif + !cnt[ar[j]] <= k)
                if(cnt[ar[j++]]++ == 0)
                    dif++;
            res += j-i;
        }
        return res;
    }
    int subarraysWithKDistinct(vector<int>& ar, int k) {
        return solve(ar,k) - solve(ar,k-1);
    }
};