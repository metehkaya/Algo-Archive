class Solution {
public:
    int countDigits(int num) {
        int n = num , ans = 0;
        while(n) {
            if(num % (n%10) == 0)
                ans++;
            n /= 10;
        }
        return ans;
    }
};
