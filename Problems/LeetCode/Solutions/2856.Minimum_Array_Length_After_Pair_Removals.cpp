class Solution {
public:
    int minLengthAfterRemovals(vector<int>& v) {
        int n = v.size() , mx = 0;
        map<int,int> mp;
        for(int x : v)
            mx = max(mx,++mp[x]);
        return 2*mx <= n ? n%2 : 2*mx-n;
    }
};
