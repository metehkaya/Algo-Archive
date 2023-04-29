class Solution {
public:
    int findInteger(int k, int d1, int d2, long long num = 0) {
        if(num > INT_MAX)
            return -1;
        if(num > k and num % k == 0)
            return (int) num;
        long long num1 = 10*num+d1 , num2 = 10*num+d2;
        int ans1 = (num == 0 and d1 == 0) ? -1 : findInteger(k,d1,d2,num1);
        int ans2 = (num == 0 and d2 == 0) ? -1 : findInteger(k,d1,d2,num2);
        if(ans1 != -1 and ans2 != -1)
            return min(ans1,ans2);
        else
            return ans1 == -1 ? ans2 : ans1;
    }
};
