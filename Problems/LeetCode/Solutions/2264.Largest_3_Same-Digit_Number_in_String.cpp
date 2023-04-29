class Solution {
public:
    string largestGoodInteger(string s) {
        char best = 0;
        int n = s.length();
        for( int i = 0 ; i <= n-3 ; i++ )
            if(s[i] == s[i+1] and s[i+1] == s[i+2])
                best = max(best,s[i]);
        if(best == 0)
            return "";
        string ans = "";
        for( int i = 0 ; i < 3 ; i++ )
            ans.push_back(best);
        return ans;
    }
};
