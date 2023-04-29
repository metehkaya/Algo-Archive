typedef long long LL;

class Solution {
public:
    int waysToSplitArray(vector<int>& ar) {
        LL sum = 0;
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ )
            sum += ar[i];
        LL curr = 0;
        int ans = 0;
        for( int i = 0 ; i < n-1 ; i++ ) {
            curr += ar[i];
            if(curr >= sum-curr)
                ans++;
        }
        return ans;
    }
};
