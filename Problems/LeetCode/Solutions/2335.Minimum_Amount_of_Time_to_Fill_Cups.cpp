class Solution {
public:
    int fillCups(vector<int>& v) {
        int ans = 0;
        sort(v.begin(),v.end());
        while(v[2] > 0) {
            ans++;
            v[2]--;
            v[1] = max(v[1]-1,0);
            sort(v.begin(),v.end());
        }
        return ans;
    }
};
