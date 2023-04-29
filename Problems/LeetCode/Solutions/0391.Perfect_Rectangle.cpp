class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rects) {
        map<vector<int>,int> mp;
        for(auto v : rects) {
            mp[{v[0],v[1]}]++;
            mp[{v[2],v[3]}]++;
            mp[{v[0],v[3]}]--;
            mp[{v[2],v[1]}]--;
        }
        int sum = 0;
        for(auto it : mp)
            sum += abs(it.second);
        return sum == 4;
    }
};
