class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        vector<int> cnt(2,0);
        for(char c : s)
            cnt[c-'0']++;
        string ans = "";
        while(--cnt[1])
            ans.push_back('1');
        while(cnt[0]--)
            ans.push_back('0');
        ans.push_back('1');
        return ans;
    }
};
