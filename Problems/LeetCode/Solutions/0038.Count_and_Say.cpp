class Solution {
public:
    string ans[31];
    string f(int num) {
        string s = "";
        while(num) {
            s.push_back('0'+(num%10));
            num /= 10;
        }
        reverse(s.begin(),s.end());
        return s;
    }
    string countAndSay(int n) {
        ans[1] = "1";
        for( int k = 1 ; k < n ; k++ ) {
            string s = ans[k];
            int len = s.length();
            for( int i = 0 , j = 0 ; i < len ; i = j ) {
                while(j < len && s[i] == s[j])
                    j++;
                ans[k+1] += f(j-i);
                ans[k+1].push_back(s[i]);
            }
        }
        return ans[n];
    }
};