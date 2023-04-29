class Solution {
public:
    string maximumBinaryString(string s) {
        int n = s.length();
        int idx = 0;
        while(idx < n && s[idx] == '1')
            idx++;
        if(idx == n)
            return s;
        int ones = 0;
        for( int i = idx+1 ; i < n ; i++ )
            if(s[i] == '1')
                ones++;
        string ans = "";
        for( int i = 0 ; i < n ; i++ )
            ans.push_back('1');
        ans[n-1-ones] = '0';
        return ans;
    }
};