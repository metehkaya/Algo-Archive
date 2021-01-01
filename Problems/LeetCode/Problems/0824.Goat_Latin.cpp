class Solution {
public:
    string conv(string& s , int cnt) {
        char c = s[0];
        char c2 = (c >= 'a') ? c : c-'A'+'a';
        int n = s.length();
        if(c2 == 'a' || c2 == 'e' || c2 == 'i' || c2 == 'o' || c2 == 'u');
        else
            s = s.substr(1,n-1) + c;
        s += "ma";
        for( int i = 0 ; i < cnt ; i++ )
            s.push_back('a');
        return s;
    }
    string toGoatLatin(string s) {
        string ans = "";
        int n = s.length() , cnt = 0;
        for( int i = 0 ; i < n ; ) {
            if(s[i] == ' ')
                ans.push_back(s[i++]);
            else {
                cnt++;
                string word = "";
                while(i < n && s[i] != ' ')
                    word.push_back(s[i++]);
                ans += conv(word,cnt);
            }
        }
        return ans;
    }
};