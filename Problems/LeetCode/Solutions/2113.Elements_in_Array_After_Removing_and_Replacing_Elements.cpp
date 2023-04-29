class Solution {
public:
    vector<int> elementInNums(vector<int>& v, vector<vector<int>>& queries) {
        int n = v.size();
        vector<int> ans;
        for(auto q : queries) {
            int t = q[0] , idx = q[1];
            int r = t % (2*n);
            if(r < n) {
                if(r+idx < n)
                    ans.push_back(v[r+idx]);
                else
                    ans.push_back(-1);
            }
            else {
                if(idx < r%n)
                    ans.push_back(v[idx]);
                else
                    ans.push_back(-1);
            }
        }
        return ans;
    }
};
