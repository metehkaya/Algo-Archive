class Solution {
public:
    int countEven(int n) {
        int ans = 0;
        for( int i = 1 ; i <= n ; i++ ) {
            int x = i , sum = 0;
            while(x) {
                sum += x%10;
                x /= 10;
            }
            if(sum % 2 == 0)
                ans++;
        }
        return ans;
    }
};
