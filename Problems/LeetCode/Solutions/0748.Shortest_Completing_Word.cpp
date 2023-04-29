class Solution {
public:
    string shortestCompletingWord(string s, vector<string>& ar) {
        int n = s.length();
        vector<int> cnt(26,0);
        for( int i = 0 ; i < n ; i++ ) {
            char c = s[i];
            if(c >= 'A' && c <= 'Z')
                cnt[c-'A']++;
            else if(c >= 'a' && c <= 'z')
                cnt[c-'a']++;
        }
        n = ar.size();
        int ans_idx = -1;
        int ans_len = INT_MAX;
        for( int i = 0 ; i < n ; i++ ) {
            int len = ar[i].length();
            if(len >= ans_len)
                continue;
            vector<int> v = cnt;
            for( int j = 0 ; j < len ; j++ )
                v[ar[i][j]-'a']--;
            bool ok = true;
            for( int j = 0 ; j < 26 ; j++ )
                if(v[j] > 0)
                    ok = false;
            if(ok)
                ans_len = len , ans_idx = i;
        }
        return ar[ans_idx];
    }
};