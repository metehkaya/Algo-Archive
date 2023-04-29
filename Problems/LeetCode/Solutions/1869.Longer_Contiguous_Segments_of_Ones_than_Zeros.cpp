class Solution {
public:
    bool checkZeroOnes(string s) {
        int mx[2] = {0,0};
        int n = s.length();
        for( int i = 0 , j = 0 ; i < n ; i = j ) {
            while(j < n && s[i] == s[j])
                j++;
            int c = s[i]-'0';
            mx[c] = max(mx[c],j-i);
        }
        return mx[1] > mx[0];
    }
};