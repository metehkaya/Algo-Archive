class Solution {
public:
    string shiftingLetters(string s, vector<int>& ar) {
        int n = s.length();
        int add = 0;
        for( int i = n-1 ; i >= 0 ; i-- ) {
            add = (add + ar[i]) % 26;
            int val = s[i]-'a';
            val = (val+add) % 26;
            s[i] = 'a'+val;
        }
        return s;
    }
};