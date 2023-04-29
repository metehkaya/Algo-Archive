class Solution {
public:
    bool check(int n) {
        bool change = false;
        while(n > 0) {
            int dig = n%10;
            if(dig == 3 || dig == 4 || dig == 7)
                return false;
            if(dig == 2 || dig == 5 || dig == 6 || dig == 9)
                change = true;
            n /= 10;
        }
        return change;
    }
    int rotatedDigits(int N) {
        int ans = 0;
        for( int i = 1 ; i <= N ; i++ )
            if(check(i))
                ans++;
        return ans;
    }
};