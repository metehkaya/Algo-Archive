class Solution {
public:
    string kthLuckyNumber(int n) {
        int n_digits = 1 , sum = 0;
        while(sum + (1<<n_digits) < n) {
            sum += (1 << n_digits);
            n_digits += 1;
        }
        n -= sum+1;
        string ans = "";
        for( int i = 0 ; i < n_digits ; i++ )
            if(n & (1<<i))
                ans.push_back('7');
            else
                ans.push_back('4');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
