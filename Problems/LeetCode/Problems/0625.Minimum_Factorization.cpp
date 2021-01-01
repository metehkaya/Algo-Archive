class Solution {
public:
    int smallestFactorization(int num) {
        if(num <= 1)
            return num;
        vector<int> v;
        for( int i = 9 ; i >= 2 ; i-- )
            while(num % i == 0) {
                num /= i;
                v.push_back(i);
            }
        if(num > 1)
            return 0;
        int n = v.size();
        if(n > 10)
            return 0;
        reverse(v.begin(),v.end());
        long long ans = 0;
        for( int i = 0 ; i < n ; i++ )
            ans = 10*ans + v[i];
        if(ans > INT_MAX)
            return 0;
        return (int)ans;
    }
};