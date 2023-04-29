class Solution {
public:
    const int VALID[5] = {0,1,6,8,9};
    bool check(int num) {
        int num2 = 0;
        int temp = num;
        while(num) {
            int dig = num%10;
            num /= 10;
            num2 *= 10;
            if(dig == 6)
                num2 += 9;
            else if(dig == 9)
                num2 += 6;
            else
                num2 += dig;
        }
        return temp != num2;
    }
    void f(int num , int index , int N , int& ans) {
        if(num > N)
            return;
        if(index == 9) {
            ans += check(num);
            return;
        }
        for( int i = 0 ; i < 5 ; i++ )
            f(num*10+VALID[i],index+1,N,ans);
    }
    int confusingNumberII(int N) {
        int ans = 0;
        f(0,0,N,ans);
        if(N == (int) 1e9)
            ans++;
        return ans;
    }
};