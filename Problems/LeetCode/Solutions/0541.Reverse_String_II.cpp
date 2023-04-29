class Solution {
public:
    string reverseStr(string s, int k) {
        string ans = "";
        int n = s.length();
        for( int i = 0 ; i < n ; i += 2*k ) {
            int len = min(n-i, k);
            string t = s.substr(i,len);
            reverse(t.begin(), t.end());
            ans = ans + t;
            if(i+k < n) {
                int ind1 = i+k;
                int ind2 = min(ind1+k, n);
                ans = ans + s.substr(ind1, ind2-ind1);
            }
        }
        return ans;
    }
};