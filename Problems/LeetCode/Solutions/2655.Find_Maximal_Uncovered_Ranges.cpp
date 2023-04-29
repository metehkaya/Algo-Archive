class Solution {
public:
    vector<vector<int>> findMaximalUncoveredRanges(int n, vector<vector<int>>& ranges) {
        map<int,int> mp;
        map<int,int>::iterator it;
        for(auto& range : ranges)
            mp[range[0]]++ , mp[range[1]+1]--;
        vector<vector<int>> ans;
        int idx = 0 , cnt = 0;
        while(idx < n) {
            it = mp.lower_bound(idx);
            if(it == mp.end()) {
                ans.push_back({idx,n-1});
                break;
            }
            if(it->first == idx) {
                cnt += it->second;
                mp.erase(it);
            }
            else {
                if(cnt == 0)
                    ans.push_back({idx,it->first-1});
                idx = it->first;
                cnt += it->second;
                mp.erase(it);
            }
        }
        return ans;
    }
};
