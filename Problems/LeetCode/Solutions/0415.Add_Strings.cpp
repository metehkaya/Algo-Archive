class Solution {
public:
    string addStrings(string s, string t) {
        int n = s.length();
        int m = t.length();
        string ans;
        reverse(s.begin(),s.end());
        reverse(t.begin(),t.end());
        for( int i = 0 , add = 0 ; i < n || i < m || add > 0 ; i++ ) {
            int val = add;
            if(i < n)
                val += s[i]-'0';
            if(i < m)
                val += t[i]-'0';
            add = val / 10;
            val %= 10;
            ans.push_back('0'+val);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};