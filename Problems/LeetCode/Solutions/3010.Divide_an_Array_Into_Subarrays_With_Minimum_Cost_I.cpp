class Solution {
public:
    int minimumCost(vector<int>& v) {
        int val = v[0];
        v.erase(v.begin());
        sort(v.begin(),v.end());
        return val+v[0]+v[1];
    }
};
