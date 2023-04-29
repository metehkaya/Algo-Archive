class Solution {
public:
    string convert(string s, int k) {
        if(k == 1)
            return s;
        int n = s.length();
        int K = 2*(--k);
        string ans = "";
        for( int i = 0 ; i < n ; i += K )
            ans.push_back(s[i]);
        for( int i = 1 ; i < k ; i++ ) {
            int j1 = i , j2 = K-i;
            while(j1 < n) {
                ans.push_back(s[j1]);
                j1 += K;
                if(j2 < n) {
                    ans.push_back(s[j2]);
                    j2 += K;
                }
            }
        }
        for( int i = k ; i < n ; i += K )
            ans.push_back(s[i]);
        return ans;
    }
};
