class Solution {
public:
    int f(int x , int y , int m) {
        int res = 1;
        x %= m;
        while(y--)
            res = res*x % m;
        return res;
    }
    vector<int> getGoodIndices(vector<vector<int>>& v, int target) {
        vector<int> ans;
        int n = v.size();
        for( int i = 0 ; i < n ; i++ ) {
            int x = f(v[i][0],v[i][1],10);
            x = f(x,v[i][2],v[i][3]);
            if(x == target)
                ans.push_back(i);
        }
        return ans;
    }
};
