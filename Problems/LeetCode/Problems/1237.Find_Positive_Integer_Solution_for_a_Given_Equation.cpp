class CustomFunction {
    int f(int x, int y);
};

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& cf, int z) {
        vector<vector<int>> ans;
        for( int i = 1 ; i <= 1000 ; i++ ) {
            vector<int> v(2,-1);
            int l = 1 , r = 1000;
            while(l <= r) {
                int m = (l+r) >> 1;
                int val = cf.f(i,m);
                if(val < z)
                    l = m+1;
                else if(val > z)
                    r = m-1;
                else {
                    v[0] = i , v[1] = m;
                    break;
                }
            }
            if(v[0] != -1)
                ans.push_back(v);
        }
        return ans;
    }
};