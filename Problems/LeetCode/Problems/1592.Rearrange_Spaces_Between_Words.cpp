class Solution {
public:
    string reorderSpaces(string s) {
        vector<string> v;
        int cnt = 0;
        int len = s.length();
        string word = "";
        for( int i = 0 ; i < len ; i++ ) {
            if(s[i] == ' ') {
                cnt++;
                if(!word.empty()) {
                    v.push_back(word);
                    word = "";
                }
            }
            else
                word.push_back(s[i]);
        }
        if(!word.empty())
            v.push_back(word);
        int n = v.size();
        string ans = v[0];
        if(n > 1) {
            int times = cnt / (n-1);
            int rem = cnt % (n-1);
            for( int i = 1 ; i < n ; i++ ) {
                for( int j = 0 ; j < times ; j++ )
                    ans.push_back(' ');
                ans += v[i];
            }
            for( int j = 0 ; j < rem ; j++ )
                ans.push_back(' ');
        }
        else
            for( int i = 0 ; i < cnt ; i++ )
                ans.push_back(' ');
        return ans;
    }
};