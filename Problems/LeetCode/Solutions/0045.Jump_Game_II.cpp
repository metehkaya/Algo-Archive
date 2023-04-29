class Solution {
public:
    int jump(vector<int>& ar) {
        int n = ar.size();
        if(n < 2)
            return 0;
        int ans = 1;
        int mxPos = ar[0];
        int mxJump = ar[0];
        for( int i = 1 ; i < n ; i++ ) {
            if(i > mxJump) {
                ans++;
                mxJump = mxPos;
            }
            mxPos = max(mxPos,i+ar[i]);
        }
        return ans;
    }
};