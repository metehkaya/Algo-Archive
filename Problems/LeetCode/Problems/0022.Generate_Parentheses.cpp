class Solution {
public:
    void f(int rem , int bal , string& curr , vector<string>& ans) {
        if(rem == 0 && bal == 0) {
            ans.push_back(curr);
            return;
        }
        if(rem) {
            curr.push_back('(');
            f(rem-1,bal+1,curr,ans);
            curr.pop_back();
        }
        if(bal) {
            curr.push_back(')');
            f(rem,bal-1,curr,ans);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr = "";
        f(n,0,curr,ans);
        return ans;
    }
};