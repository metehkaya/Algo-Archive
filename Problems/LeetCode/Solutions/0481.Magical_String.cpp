class Solution {
public:
    int magicalString(int n) {
        vector<int> v(3);
        v[0] = 1 , v[1] = v[2] = 2;
        for( int i = 2 ; i < n ; i++ ) {
            int val = (i%2)+1;
            for( int j = 0 ; j < v[i] ; j++ )
                v.push_back(val);
        }
        int ans = 0;
        for( int i = 0 ; i < n ; i++ )
            ans += 2-v[i];
        return ans;
    }
};
