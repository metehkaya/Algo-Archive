class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for( int x = low ; x <= high ; x++ ) {
            string s = to_string(x);
            int n = s.length();
            if(n % 2 == 1)
                continue;
            int sum = 0;
            for( int i = 0 ; i < n/2 ; i++ )
                sum += s[i];
            for( int i = n/2 ; i < n ; i++ )
                sum -= s[i];
            ans += (sum == 0);
        }
        return ans;
    }
};
