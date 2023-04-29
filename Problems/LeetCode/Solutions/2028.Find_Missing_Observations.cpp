class Solution {
public:
    vector<int> missingRolls(vector<int>& ar, int mean, int n) {
        int m = ar.size();
        int sum = 0;
        for( int i = 0 ; i < m ; i++ )
            sum += ar[i];
        sum = mean*(n+m) - sum;
        vector<int> ans;
        if(sum < n || sum > 6*n)
            return ans;
        ans.resize(n,1);
        sum -= n;
        int k = sum/5;
        for( int i = 0 ; i < k ; i++ )
            ans[i] = 6;
        if(sum % 5)
            ans[k] += sum%5;
        return ans;
    }
};
