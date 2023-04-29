class Solution {
public:
    void change(char c, int& num) {
        if(c == 'a')
            num ^= 1;
        else if(c == 'e')
            num ^= 2;
        else if(c == 'i')
            num ^= 4;
        else if(c == 'o')
            num ^= 8;
        else if(c == 'u')
            num ^= 16;
    }
    int findTheLongestSubstring(string s) {
        vector<int> first(32,-1);
        first[0] = 0;
        int n = s.length();
        int curr = 0, ans = 0;
        for( int i = 0 ; i < n ; i++ ) {
            char c = s[i];
            change(c,curr);
            if(first[curr] == -1)
                first[curr] = i+1;
            else
                ans = max(ans, i+1-first[curr]);
        }
        return ans;
    }
};