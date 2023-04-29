class Solution {
public:
    int n;
    string s;
    vector<string> ans;
    void f(int i , string& t) {
        if(i == n) {
            ans.push_back(t);
            return;
        }
        t.push_back(s[i]);
        f(i+1,t);
        t.pop_back();
        if(s[i] >= 'a' && s[i] <= 'z') {
            t.push_back(s[i]-'a'+'A');
            f(i+1,t);
            t.pop_back();
        }
        else if(s[i] >= 'A' && s[i] <= 'Z') {
            t.push_back(s[i]-'A'+'a');
            f(i+1,t);
            t.pop_back();
        }
    }
    vector<string> letterCasePermutation(string s) {
        this->s = s;
        string t = "";
        n = s.length();
        f(0,t);
        return ans;
    }
};