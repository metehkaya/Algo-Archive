class Solution {
public:
    const int mod = (int) 1e9 + 7;
    int min_sum,max_sum;
    int dp[23][401][2];
    int f(int idx , int sum , bool smaller , string& s) {
        if(idx == 23)
            return ((min_sum <= sum) && (sum <= max_sum));
        if(dp[idx][sum][smaller] != -1)
            return dp[idx][sum][smaller];
        dp[idx][sum][smaller] = 0;
        for( char c = '0' ; c <= '9' ; c++ )
            if((c <= s[idx]) or smaller)
                dp[idx][sum][smaller] = (dp[idx][sum][smaller] + f(idx+1,sum+c-'0',(smaller or (c < s[idx])),s)) % mod;
        return dp[idx][sum][smaller];
    }
    int count(string s1, string s2, int min_sum, int max_sum) {
        this->min_sum = min_sum;
        this->max_sum = max_sum;
        s1.insert(0, 23-s1.length(), '0');
        s2.insert(0, 23-s2.length(), '0');
        memset(dp,-1,sizeof(dp));
        int ans = f(0,0,false,s2);
        memset(dp,-1,sizeof(dp));
        ans = (ans - f(0,0,false,s1) + mod) % mod;
        int sum = 0;
        for(char c : s1)
            sum += c-'0';
        ans = (ans + ((min_sum <= sum) && (sum <= max_sum))) % mod;
        return ans;
    }
};
