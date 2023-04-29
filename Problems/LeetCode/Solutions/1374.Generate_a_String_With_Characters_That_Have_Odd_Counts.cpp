class Solution {
public:
    string generateTheString(int n) {
        string ans = "a";
        for( int i = 3 ; i <= n ; i += 2 )
            ans += "aa";
        if(n % 2 == 0)
            ans.push_back('b');
        return ans;
    }
};