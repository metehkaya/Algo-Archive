class Solution {
public:
    vector<int> factors;
    vector<vector<int>> ans;
    void f(int n , int k , vector<int>& v) {
        if(n == 1) {
            if(!v.empty())
                ans.push_back(v);
            return;
        }
        int m = factors.size();
        for( int i = k ; i < m ; i++ )
            if(n % factors[i] == 0) {
                v.push_back(factors[i]);
                f(n/factors[i],i,v);
                v.pop_back();
            }
    }
    vector<vector<int>> getFactors(int n) {
        for( int i = 2 ; i*i <= n ; i++ )
            if(n % i == 0) {
                factors.push_back(i);
                if(i*i < n)
                    factors.push_back(n/i);
            }
        sort(factors.begin(),factors.end());
        vector<int> v;
        f(n,0,v);
        return ans;
    }
};