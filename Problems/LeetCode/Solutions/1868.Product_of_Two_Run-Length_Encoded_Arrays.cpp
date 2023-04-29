class Solution {
public:
    vector<vector<int>> findRLEArray(vector<vector<int>>& v1, vector<vector<int>>& v2) {
        vector<vector<int>> ans;
        int mult_val = 0 , mult_cnt = 0;
        int i = 0 , j = 0 , n = v1.size() , m = v2.size();
        while(i < n and j < m) {
            int new_mult_val = v1[i][0]*v2[j][0];
            int new_mult_cnt = min(v1[i][1],v2[j][1]);
            v1[i][1] -= new_mult_cnt;
            v2[j][1] -= new_mult_cnt;
            if(v1[i][1] == 0)
                i++;
            if(v2[j][1] == 0)
                j++;
            if(new_mult_val == mult_val)
                mult_cnt += new_mult_cnt;
            else {
                if(mult_val)
                    ans.push_back({mult_val,mult_cnt});
                mult_val = new_mult_val;
                mult_cnt = new_mult_cnt;
            }
        }
        ans.push_back({mult_val,mult_cnt});
        return ans;
    }
};
