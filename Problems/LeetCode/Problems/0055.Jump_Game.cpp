class Solution {
public:
    bool canJump(vector<int>& ar) {
        int n = ar.size();
        int mx = 0;
        for( int i = 0 ; i < n && i <= mx ; i++ )
            mx = max( mx , i+ar[i] );
        return mx >= n-1;
    }
};