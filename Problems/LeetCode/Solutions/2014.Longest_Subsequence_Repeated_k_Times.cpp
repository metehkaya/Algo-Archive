class Solution {
public:
    int get_freq(string& str, string& s) {
        int cnt = 0 , len = str.length();
        for( int i = 0 , idx = 0 ; i < len ; i++ ) {
            if(str[i] == s[idx])
                idx++;
            if(idx == s.length()) {
                idx = 0;
                cnt++;
            }
        }
        return cnt;
    }
    string longestSubsequenceRepeatedK(string str, int k) {
        queue<string> q;
        q.push("");
        string ans;
        while(!q.empty()) {
            string s = q.front();
            q.pop();
            ans = s;
            for( int i = 0 ; i < 26 ; i++ ) {
                string t = s + string(1,'a'+i);
                if(get_freq(str,t) >= k)
                    q.push(t);
            }
        }
        return ans;
    }
};
