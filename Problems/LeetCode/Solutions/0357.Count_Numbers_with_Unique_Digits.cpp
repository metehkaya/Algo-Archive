class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int ans = 1;
        for( int i = 1 , num = 1 ; i <= n ; i++ ) {
            if(i == 1)
                num = 9;
            else
                num *= 9-(i-2);
            ans += num;
        }
        return ans;
    }
};