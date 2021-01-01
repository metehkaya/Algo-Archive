class Solution {
public:
    string mp[8] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void f(int i , string& curr , string& s , vector<string>& ans) {
        if(i == s.length()) {
            ans.push_back(curr);
            return;
        }
        int idx = s[i]-'2';
        for( int j = 0 ; j < mp[idx].length() ; j++ ) {
            curr.push_back(mp[idx][j]);
            f(i+1,curr,s,ans);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string s) {
        vector<string> ans;
        if(s.empty())
            return ans;
        string curr = "";
        f(0,curr,s,ans);
        return ans;
    }
};