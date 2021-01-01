class Solution {
public:
    int maxDiff(int num) {
        vector<int> sum(10,0);
        int base10 = 1;
        int temp = num;
        while(temp) {
            int dig = temp % 10;
            temp /= 10;
            sum[dig] += base10;
            base10 *= 10;
        }
        base10 /= 10;
        int mx = num , mn = num;
        for( int i = 0 ; i < 10 ; i++ )
            for( int j = 0 ; j < 10 ; j++ ) {
                if(sum[i] >= base10 && j == 0)
                    continue;
                int total = num + sum[i] * (j-i);
                mx = max(mx, total);
                mn = min(mn, total);
            }
        return mx-mn;
    }
};