class Solution {
public:
    int busyStudent(vector<int>& s, vector<int>& e, int t) {
        int ans = 0;
        int n = s.size();
        for( int i = 0 ; i < n ; i++ )
            ans += s[i] <= t && t <= e[i];
        return ans;
    }
};