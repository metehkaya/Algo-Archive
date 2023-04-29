class Solution {
public:
    int f(string& s , int score , char c1 , char c2) {
        int res = 0;
        string curr = "";
        int len = s.length();
        for( int i = 0 ; i < len ; i++ ) {
            char c = s[i];
            if(curr.empty() || c != c2)
                curr.push_back(c);
            else if(curr.back() == c1) {
                res += score;
                curr.pop_back();
            }
            else
                curr.push_back(c);
        }
        s = curr;
        return res;
    }
    int maximumGain(string s, int x, int y) {
        int ans = 0;
        string t = s;
        if(x >= y) {
            ans += f(t,x,'a','b');
            ans += f(t,y,'b','a');
        }
        else {
            ans += f(t,y,'b','a');
            ans += f(t,x,'a','b');
        }
        return ans;
    }
};