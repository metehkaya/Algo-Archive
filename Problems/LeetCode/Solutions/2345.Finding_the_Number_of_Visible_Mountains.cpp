class Solution {
public:
    int visibleMountains(vector<vector<int>>& peaks) {
        map<int,vector<int>> mp;
        for(auto& v : peaks) {
            int l = v[0]-v[1] , r = v[0]+v[1];
            vector<int> val(2,INT_MIN);
            if(mp.count(l)) {
                val = mp[l];
                if(r >= val[0])
                    val[1] = val[0] , val[0] = r;
                else if(r >= val[1])
                    val[1] = r;
            }
            else
                val[0] = r;
            mp[l] = val;
        }
        int mx = INT_MIN , ans = 0;
        for(auto iter : mp) {
            auto v = iter.second;
            if(v[0] != v[1] and v[0] > mx)
                ans++;
            mx = max(mx,v[0]);
        }
        return ans;
    }
};
