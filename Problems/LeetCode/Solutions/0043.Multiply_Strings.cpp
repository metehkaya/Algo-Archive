class Solution {
public:
    void addNumber(string& ans, int index, int val) {
        while(index >= ans.length())
            ans.push_back('0');
        int sum = (ans[index]-'0')+val;
        int add = sum / 10;
        sum %= 10;
        ans[index] = (char)('0'+sum);
        if(add)
            addNumber(ans,index+1,add);
    }
    string multiply(string s, string t) {
        string ans = "0";
        int n = s.length();
        int m = t.length();
        for( int j = m-1 ; j >= 0 ; j-- ) {
            int add = 0;
            for( int i = n-1 ; i >= 0 ; i-- ) {
                int mult = (s[i]-'0') * (t[j]-'0');
                int sum = mult + add;
                add = sum / 10;
                sum %= 10;
                int index = (n-1-i) + (m-1-j);
                addNumber(ans,index,sum);
            }
            if(add) {
                int index = (m-1-j) + n;
                addNumber(ans,index,add);
            }
        }
        while(ans.length() > 1 && ans[ans.length()-1] == '0')
            ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};