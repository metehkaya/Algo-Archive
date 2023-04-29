class Solution {
public:
    int n;
    int cnt[50][26];
    bool char_exists[26];
    unordered_map<string,int> dp;
    int solve(string& s) {
        cout << s << endl;
        if(s == "")
            return 0;
        auto it = dp.find(s);
        if(it != dp.end())
            return it->second;
        int res = INT_MAX;
        vector<int> cnt_s(26,0);
        for(char c : s)
            cnt_s[c-'a']++;
        for( int i = 0 ; i < n ; i++ )
            if(cnt[i][s[0]-'a']) {
                string new_s = "";
                for( int j = 0 ; j < 26 ; j++ )
                    new_s += string(max(cnt_s[j]-cnt[i][j],0), 'a'+j);
                res = min(res, solve(new_s)+1);
            }
        return dp[s] = res;
    }
    int minStickers(vector<string>& words, string target) {
        n = words.size();
        memset(cnt,0,sizeof(cnt));
        memset(char_exists,false,sizeof(char_exists));
        for( int i = 0 ; i < n ; i++ )
            for(char c : words[i])
                cnt[i][c-'a']++ , char_exists[c-'a'] = true;
        for(char c : target)
            if(!char_exists[c-'a'])
                return -1;
        return solve(target);
    }
};
