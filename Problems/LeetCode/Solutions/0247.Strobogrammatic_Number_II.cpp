class Solution {
public:
    vector<string> ans;
    void f(int i , int j , string& s) {
        if(i > j) {
            ans.push_back(s);
            return;
        }
        else if(i == j) {
            if(i or j == 0) {
                s[i] = '0';
                ans.push_back(s);
            }
            s[i] = '1';
            ans.push_back(s);
            s[i] = '8';
            ans.push_back(s);
            return;
        }
        else if(i < j) {
            if(i) {
                s[i] = s[j] = '0';
                f(i+1,j-1,s);
            }
            s[i] = s[j] = '1';
            f(i+1,j-1,s);
            s[i] = s[j] = '8';
            f(i+1,j-1,s);
            s[i] = '6' , s[j] = '9';
            f(i+1,j-1,s);
            s[i] = '9' , s[j] = '6';
            f(i+1,j-1,s);
        }
    }
    vector<string> findStrobogrammatic(int n) {
        string s(n,'-');
        f(0,n-1,s);
        return ans;
    }
};
