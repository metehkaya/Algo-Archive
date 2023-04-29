class Solution {
public:
    int minimumBoxes(int n) {
        int ans = 0;
        for( int i = 1 ; n > 0 ; i++ )
            for( int j = 1 ; j <= i && n > 0 ; j++ )
                n -= j , ans++;
        return ans;
    }
};
