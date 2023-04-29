class Solution {
public:
    bool divisorGame(int n) {
        vector<bool> ans(n+1,false);
        for( int num = 2 ; num <= n ; num++ ) {
            for( int i = 1 ; i*i <= n ; i++ )
                if(num % i == 0) {
                    int j = num/i;
                    ans[num] = ans[num] || !ans[num-i];
                    if(j != num)
                        ans[num] = ans[num] || !ans[num-j];
                }
        }
        return ans[n];
    }
};