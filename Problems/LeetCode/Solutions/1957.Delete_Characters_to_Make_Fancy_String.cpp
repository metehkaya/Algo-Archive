class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        int n = s.length();
        for( int i = 0 , j = 0 ; i < n ; i = j ) {
            while(j < n && s[i] == s[j])
                j++;
            int k = min(j-i,2);
            while(k--)
                ans.push_back(s[i]);
        }
        return ans;
    }
};