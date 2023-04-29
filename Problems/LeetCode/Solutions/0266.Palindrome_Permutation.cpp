class Solution {
public:
    bool canPermutePalindrome(string s) {
        int n = s.length();
        vector<int> cnt(256,0);
        for( int i = 0 ; i < n ; i++ )
            cnt[s[i]]++;
        int total = 0;
        for( int i = 0 ; i < 256 ; i++ )
            total += cnt[i]%2;
        return total < 2;
    }
};