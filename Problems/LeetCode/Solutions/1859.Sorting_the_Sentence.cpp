class Solution {
public:
    string sortSentence(string s) {
        vector<string> v;
        s.push_back(' ');
        int n = s.length();
        int times = 0;
        string word = "";
        for( int i = 0 ; i < n ; i++ ) {
            if(s[i] == ' ') {
                if(times > v.size())
                    v.resize(times);
                v[times-1] = word;
                word = "";
            }
            else if(s[i] >= '0' && s[i] <= '9')
                times = s[i]-'0';
            else
                word.push_back(s[i]);
        }
        n = v.size();
        string ans = v[0];
        for( int i = 1 ; i < n ; i++ )
            ans += " " + v[i];
        return ans;
    }
};