class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& s) {
        int n = s.size() , ans = 0;
        s.push_back(s[0]);
        s.push_back(s[1]);
        for( int i = 1 ; i <= n ; i++ )
            if(s[i] != s[i-1] and s[i] != s[i+1])
                ans++;
        return ans;
    }
};