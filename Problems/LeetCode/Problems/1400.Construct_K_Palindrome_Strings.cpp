class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.length();
        vector<int> cnt(26,0);
        for( int i = 0 ; i < n ; i++ )
            cnt[s[i]-'a']++;
        int cntOdd = 0;
        for( int i = 0 ; i < 26 ; i++ )
            if(cnt[i] % 2)
                cntOdd++;
        if(cntOdd > k || k > n)
            return false;
        return true;
    }
};