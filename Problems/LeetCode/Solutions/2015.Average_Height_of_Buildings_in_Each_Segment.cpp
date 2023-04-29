typedef long long LL;

class Solution {
public:
    vector<vector<int>> averageHeightOfBuildings(vector<vector<int>>& buildings) {
        map<int,vector<int>> mp;
        for(auto v : buildings) {
            mp[v[0]].push_back(v[2]);
            mp[v[1]].push_back(-v[2]);
        }
        int last_avg = -1 , last_idx = -1 , n = 0;
        LL sum = 0;
        vector<vector<int>> ans;
        for(auto it : mp) {
            int idx = it.first;
            for(int val : it.second) {
                sum += val;
                n += (val > 0) ? +1 : -1;
            }
            int avg = (n == 0) ? -1 : sum/n;
            if(last_avg == -1) {
                last_avg = avg;
                last_idx = idx;
            }
            else if(avg != last_avg) {
                ans.push_back({last_idx,idx,last_avg});
                last_avg = avg;
                last_idx = idx;
            }
        }
        return ans;
    }
};
