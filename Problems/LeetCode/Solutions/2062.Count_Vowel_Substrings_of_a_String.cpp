class Solution {
public:
    int countVowelSubstrings(string word) {
        int n = word.length() , ans = 0;
        string t = "aeiou";
        for( int i = 0 ; i < n ; i++ )
            for( int l = 1 ; l <= n-i ; l++ ) {
                string s = word.substr(i,l);
                int bmask = 0 , cnt = 0;
                for( int k = 0 ; k < 5 ; k++ )
                    for( int idx = 0 ; idx < l ; idx++ )
                        if(s[idx] == t[k])
                            cnt++ , bmask |= (1<<k);
                if(bmask == 31 && cnt == l)
                    ans++;
            }
        return ans;
    }
};
