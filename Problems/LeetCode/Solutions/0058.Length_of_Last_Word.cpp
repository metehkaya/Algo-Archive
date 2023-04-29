class Solution {
public:
    int lengthOfLastWord(string s) {
        s.push_back(' ');
        int cnt = 0 , last = 0;
        int len = s.length();
        for( int i = 0 ; i < len ; i++ ) {
            if(s[i] == ' ') {
                if(cnt)
                    last = cnt;
                cnt = 0;
            }
            else
                cnt++;
        }
        return last;
    }
};