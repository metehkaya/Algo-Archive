class Solution {
public:
    vector<int> circularPermutation(int n, int s) {
        int N = (1<<n);
        vector<int> ans(N);
        for( int i = 0 ; i < N ; i++ )
            ans[i] = s ^ i ^ (i >> 1);
        return ans;
    }
};