class Solution {
public:
    int n,k;
    vector<int> v,sum,dp;
    int f(int idx) {
        if(dp[idx] != -1)
            return dp[idx];
        if(sum[n]-sum[idx]+(n-1-idx) <= k)
            return 0;
        int rem = k;
        dp[idx] = INT_MAX;
        for( int i = idx ; i < n ; i++ ) {
            rem -= v[i];
            if(rem < 0)
                break;
            dp[idx] = min(dp[idx],f(i+1)+rem*rem);
            rem--;
        }
        return dp[idx];
    }
    int minimumCost(string s, int k) {
        this->k = k;
        int cnt = 0;
        sum.push_back(0);
        s.push_back(' ');
        for(char c : s) {
            if(c == ' ') {
                v.push_back(cnt);
                sum.push_back(sum.back()+cnt);
                cnt = 0;
            }
            else
                cnt++;
        }
        n = v.size();
        dp.resize(n,-1);
        return f(0);
    }
};
