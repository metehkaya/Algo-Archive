class Solution {
public:
    bool equalFrequency(string s) {
        vector<int> cnt(26,0);
        for(char c : s)
            cnt[c-'a']++;
        for( int i = 0 ; i < 26 ; i++ )
            if(cnt[i]) {
                cnt[i]--;
                int mn = INT_MAX , mx = INT_MIN;
                for( int j = 0 ; j < 26 ; j++ )
                    if(cnt[j]) {
                        mn = min(mn,cnt[j]);
                        mx = max(mx,cnt[j]);
                    }
                if(mn == mx)
                    return true;
                cnt[i]++;
            }
        return false;
    }
};
