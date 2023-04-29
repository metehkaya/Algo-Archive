class Solution {
public:
    int brightestPosition(vector<vector<int>>& lights) {
        map<int,int> mp;
        for(auto v : lights) {
            mp[v[0]-v[1]]++;
            mp[v[0]+v[1]+1]--;
        }
        int curr = 0 , best = INT_MIN , ans = INT_MIN;
        for(auto it : mp) {
            curr += it.second;
            if(curr > best)
                best = curr , ans = it.first;
        }
        return ans;
    }
};
