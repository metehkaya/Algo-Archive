class Solution {
public:
    string licenseKeyFormatting(string str, int k) {
        string ans = "";
        int cnt = 0;
        int n = str.length();
        for( int i = n-1 ; i >= 0 ; i-- )
            if( str[i] != '-' ) {
                char c;
                if(str[i] >= 'a' && str[i] <= 'z')
                    c = str[i] - 'a' + 'A';
                else
                    c = str[i];
                if(cnt > 0 && cnt % k == 0)
                    ans += "-";
                cnt++;
                ans += c;
            }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};