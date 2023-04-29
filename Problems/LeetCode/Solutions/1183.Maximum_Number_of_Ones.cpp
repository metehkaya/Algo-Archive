class Solution {
public:
    int maximumNumberOfOnes(int w, int h, int n, int ones) {
        vector<int> v;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < n ; j++ ) {
                int x = h/n + (i < h%n);
                int y = w/n + (j < w%n);
                v.push_back(x*y);
            }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        int ans = 0;
        for( int i = 0 ; i < ones ; i++ )
            ans += v[i];
        return ans;
    }
};
