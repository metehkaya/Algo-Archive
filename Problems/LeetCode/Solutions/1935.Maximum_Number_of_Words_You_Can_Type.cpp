class Solution {
public:
    bool avoid[256];
    int canBeTypedWords(string s, string brokenLetters) {
        int ans = 0;
        int len = brokenLetters.length();
        for( int i = 0 ; i < len ; i++ )
            avoid[brokenLetters[i]] = true;
        s.push_back(' ');
        len = s.length();
        for( int i = 0 , j ; i < len ; i = j+1 ) {
            j = i;
            int add = 1;
            while(j < len && s[j] != ' ')
                if(avoid[s[j++]])
                    add = 0;
            ans += add;
        }
        return ans;
    }
};