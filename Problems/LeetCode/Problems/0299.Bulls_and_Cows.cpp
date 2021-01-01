class Solution {
public:
    string getStr(int num) {
        if(num == 0)
            return "0";
        string str = "";
        while(num) {
            char c = '0' + (num%10);
            str.push_back(c);
            num /= 10;
        }
        reverse(str.begin(), str.end());
        return str;
    }
    string getHint(string s, string t) {
        int n = s.length();
        int cntS[10] = {0};
        int cntT[10] = {0};
        int cntA=0,cntB=0;
        for( int i = 0 ; i < n ; i++ ) {
            if(s[i] == t[i])
                cntA++;
            else
                cntS[s[i]-'0']++, cntT[t[i]-'0']++;
        }
        for( int i = 0 ; i < 10 ; i++ )
            cntB += min(cntS[i], cntT[i]);
        string ans = "";
        ans += getStr(cntA);
        ans.push_back('A');
        ans += getStr(cntB);
        ans.push_back('B');
        return ans;
    }
};