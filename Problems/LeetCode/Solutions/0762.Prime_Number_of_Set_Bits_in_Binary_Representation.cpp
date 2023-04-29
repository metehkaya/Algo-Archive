class Solution {
public:
    bool ok[21] = {0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0};
    int f(int num) {
        int cnt = 0;
        while(num) {
            cnt += num%2;
            num /= 2;
        }
        return ok[cnt];
    }
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for( int i = left ; i <= right ; i++ )
            ans += f(i);
        return ans;
    }
};