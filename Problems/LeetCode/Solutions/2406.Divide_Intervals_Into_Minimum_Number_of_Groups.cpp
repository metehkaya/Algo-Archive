class Solution {
public:
    int minGroups(vector<vector<int>>& ar) {
        map<int,int> add;
        for(vector<int>& v : ar)
            add[v[0]]++ , add[v[1]+1]--;
        int curr = 0 , ans = 0;
        for(auto it : add) {
            curr += it.second;
            ans = max(ans,curr);
        }
        return ans;
    }
};
