class Solution {
public:
    int findNthDigit(int n) {
        int ans = -1;
        for( int i = 1 , l = 1 , u = 10 ; i <= 9 ; i++ , l *= 10 , u *= 10 ) {
            long long all = 1LL * (u-l) * i;
            if(n > all)
                n -= all;
            else {
                int num = l+(n-1)/i;
                int dig = (n-1)%i;
                vector<int> v;
                while(num) {
                    v.push_back(num%10);
                    num /= 10;
                }
                ans = v[i-1-dig];
                break;
            }
        }
        return ans;
    }
};
