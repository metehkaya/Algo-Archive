class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        int n = s.length();
        vector<vector<int>> ans;
        for( int i = 0 , j = 0 ; i < n ; i = j ) {
            while(j < n && s[i] == s[j])
                j++;
            if(j-i >= 3) {
                vector<int> v(2);
                v[0] = i;
                v[1] = j-1;
                ans.push_back(v);
            }
        }
        return ans;
    }
};