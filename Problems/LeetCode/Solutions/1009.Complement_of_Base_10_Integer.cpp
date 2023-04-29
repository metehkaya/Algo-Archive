class Solution {
public:
    int bitwiseComplement(int n) {
        string s = "";
        while(n) {
            s.push_back('0' + (n%2));
            n /= 2;
        }
        if(s == "")
            s = "0";
        reverse(s.begin(),s.end());
        n = 0;
        for( int i = 0 ; i < s.length() ; i++ )
            n = 2*n + 1-(s[i]-'0');
        return n;
    }
};