class Solution {
public:
    int missingInteger(vector<int>& v) {
        set<int> s(v.begin(), v.end());
        int n = v.size() , idx = 1 , ans = v[0];
        while(idx < n and v[idx] == v[idx-1]+1)
            ans += v[idx++];
        while(s.count(ans))
            ans++;
        return ans;
    }
};
