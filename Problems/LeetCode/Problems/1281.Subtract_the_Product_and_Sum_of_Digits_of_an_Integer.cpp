class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum = 0 , mult = 1;
        while(n) {
            int dig = n%10;
            n /= 10;
            sum += dig;
            mult *= dig;
        }
        return mult-sum;
    }
};