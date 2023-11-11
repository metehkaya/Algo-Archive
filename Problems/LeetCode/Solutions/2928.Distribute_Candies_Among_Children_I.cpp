class Solution {
public:
    int distributeCandies(int n, int limit) {
        int ans = 0;
        for( int i = 0 ; i <= limit ; i++ )
            for( int j = 0 ; j <= limit ; j++ )
                if(0 <= n-i-j and n-i-j <= limit)
                    ans++;
        return ans;
    }
};
