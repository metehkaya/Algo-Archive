class Solution {
public:
    bool isVowel(char c) {
        if(c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u')
            return true;
        if(c == 'A' or c == 'E' or c == 'I' or c == 'O' or c == 'U')
            return true;
        return false;
    }
    string reverseVowels(string s) {
        string vowels = "";
        int n = s.length();
        for( int i = 0 ; i < n ; i++ )
            if(isVowel(s[i]))
                vowels.push_back(s[i]);
        int cnt = vowels.size();
        for( int i = 0 ; i < n ; i++ )
            if(isVowel(s[i]))
                s[i] = vowels[--cnt];
        return s;
    }
};