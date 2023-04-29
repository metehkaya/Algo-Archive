class Solution {
public:
    int prefixCount(vector<string>& words, string t) {
        int len = t.length() , ans = 0;
        for(string s : words)
            if(s.length() >= len && s.substr(0,len) == t)
                ans++;
        return ans;
    }
};
