class Solution {
public:
    string repeatLimitedString(string s, int lim) {
        vector<int> cnt(26,0);
        for(char c : s)
            cnt[c-'a']++;
        string ans;
        for( int i = 25 ; i >= 0 ; ) {
            if(cnt[i] == 0) {
                i--;
                continue;
            }
            if(cnt[i] <= lim) {
                while(cnt[i]--)
                    ans.push_back('a'+i);
                i--;
                continue;
            }
            for( int j = 0 ; j < lim ; j++ )
                ans.push_back('a'+i);
            cnt[i] -= lim;
            int prev = i-1;
            while(prev >= 0 && cnt[prev] == 0)
                prev--;
            if(prev < 0)
                return ans;
            ans.push_back('a'+prev);
            cnt[prev]--;
        }
        return ans;
    }
};
