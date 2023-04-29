class Solution {
public:
    int maxDepthBST(vector<int>& v) {
        int n = v.size() , ans = 0;
        map<int,vector<int>> mp;
        mp[n] = {1,1};
        for(int x : v) {
            auto it = mp.lower_bound(x);
            int upper = it->first;
            int lower = it->second[0];
            int level = it->second[1];
            ans = max(ans,level);
            mp.erase(it);
            if(x > lower)
                mp[x-1] = {lower, level+1};
            if(x < upper)
                mp[upper] = {x+1, level+1};
        }
        return ans;
    }
};
