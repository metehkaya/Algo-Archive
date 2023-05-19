class Solution {
public:
    int countSeniors(vector<string>& v) {
        int ans = 0;
        for(string& s : v) {
            int c1 = s[11]-'0' , c2 = s[12]-'0';
            ans += (10*c1+c2) > 60;
        }
        return ans;
    }
};
