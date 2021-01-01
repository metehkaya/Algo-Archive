class Solution {
public:
    string reverseOnlyLetters(string S) {
        vector<char> v;
        int n = S.length();
        for( int i = 0 ; i < n ; i++ ) {
            char c = S[i];
            if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
                v.push_back(c);
        }
        for( int i = 0 , j = v.size() ; i < n ; i++ ) {
            char c = S[i];
            if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
                S[i] = v[--j];
        }
        return S;
    }
};