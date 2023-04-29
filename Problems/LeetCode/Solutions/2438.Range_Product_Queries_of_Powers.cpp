class Solution {
public:
    const int mod = (int) 1e9+7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int sum = 0;
        vector<int> v;
        for( int i = 0 ; i < 30 ; i++ )
            if(n & (1<<i)) {
                sum += i;
                v.push_back(sum);
            }
        vector<int> ans;
        for(vector<int>& q : queries) {
            int x = v[q[1]] - (q[0] > 0 ? v[q[0]-1] : 0);
            int add = 1;
            while(x--)
                add = 2*add % mod;
            ans.push_back(add);
        }
        return ans;
    }
};
