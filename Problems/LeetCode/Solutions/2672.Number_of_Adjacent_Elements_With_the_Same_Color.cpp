class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<int> v(n,0);
        int res = 0;
        for(auto& q : queries) {
            int idx = q[0] , c = q[1];
            if(v[idx] > 0) {
                if(idx-1 >= 0 and v[idx] == v[idx-1])
                    res--;
                if(idx+1 < n and v[idx] == v[idx+1])
                    res--;
            }
            v[idx] = c;
            if(idx-1 >= 0 and v[idx] == v[idx-1])
                res++;
            if(idx+1 < n and v[idx] == v[idx+1])
                res++;
            ans.push_back(res);
        }
        return ans;
    }
};
