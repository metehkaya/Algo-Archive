typedef long long LL;

class Solution {
public:
    long long countVowels(string word) {
        LL ans = 0;
        string s = "aeiou";
        int n = word.length();
        for( int i = 0 ; i < n ; i++ ) {
            bool ok = false;
            for( int j = 0 ; j < 5 ; j++ )
                if(word[i] == s[j])
                    ok = true;
            if(ok)
                ans += (LL) (i+1) * (n-i);
        }
        return ans;
    }
};
