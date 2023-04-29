class Solution {
public:
    int subsetXORSum(vector<int>& ar) {
        int n = ar.size();
        int N = (1<<n);
        int ans = 0;
        for( int bmask = 0 ; bmask < N ; bmask++ ) {
            int val = 0;
            for( int i = 0 ; i < n ; i++ )
                if(bmask & (1<<i))
                    val ^= ar[i];
            ans += val;
        }
        return ans;
    }
};