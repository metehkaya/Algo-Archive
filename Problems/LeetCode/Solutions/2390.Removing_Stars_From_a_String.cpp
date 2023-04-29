class Solution {
public:
    static const int maxn = 100003;
    int st[maxn];
    string removeStars(string s) {
        int n = s.length() , idx = 0;
        for( int i = 0 ; i < n ; i++ )
            if(s[i] == '*')
                idx--;
            else
                st[idx++] = i;
        string ans = "";
        for( int i = 0 ; i < idx ; i++ )
            ans.push_back(s[st[i]]);
        return ans;
    }
};
