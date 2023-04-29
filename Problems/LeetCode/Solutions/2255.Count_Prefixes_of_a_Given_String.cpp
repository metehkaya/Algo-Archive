class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int n = words.size() , ans = 0 , slen = s.length();
        for( int i = 0 ; i < n ; i++ ) {
            string t = words[i];
            int tlen = t.length();
            if(tlen <= slen && t == s.substr(0,tlen))
                ans++;
        }
        return ans;
    }
};
