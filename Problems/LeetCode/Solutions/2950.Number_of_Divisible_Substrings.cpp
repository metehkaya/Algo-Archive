class Solution {
public:
    int countDivisibleSubstrings(string s) {
        int n = s.length() , ans = 0;
        vector<int> sum({0});
        for(char ch : s) {
            int c = ch-'a';
            sum.push_back(sum.back()+(c+1)/3+1);
        }
        for( int i = 1 ; i <= n ; i++ )
            for( int j = 0 ; j < i ; j++ )
                if((sum[i]-sum[j]) % (i-j) == 0)
                    ans++;
        return ans;
    }
};
