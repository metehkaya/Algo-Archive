class Solution {
public:
    int minSubarray(vector<int>& ar, int p) {
        int n = ar.size() , sum = 0;
        for( int i = 0 ; i < n ; i++ ) {
            ar[i] %= p;
            sum = (sum + ar[i]) % p;
        }
        if(sum == 0)
            return 0;
        int ans = n;
        map<int,int> idx;
        map<int,int>::iterator it;
        idx[0] = 0;
        for( int i = 1 , curr = 0 ; i <= n ; i++ ) {
            curr = (curr + ar[i-1]) % p;
            it = idx.find((curr-sum+p)%p);
            if(it != idx.end())
                ans = min(ans,i-it->second);
            idx[curr] = i;
        }
        return (ans == n) ? -1 : ans;
    }
};