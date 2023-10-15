class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        vector<int> ones;
        for( int i = 0 ; i < n ; i++ )
            if(s[i] == '1')
                ones.push_back(i);
        int n_ones = ones.size();
        if(n_ones < k)
            return "";
        string ans = s;
        for( int i = 0 ; i <= n_ones-k ; i++ ) {
            int j = i+k-1;
            int l = ones[i] , r = ones[j];
            string t = s.substr(l,r-l+1);
            if(t.length() < ans.length())
                ans = t;
            else if(t.length() == ans.length() and t < ans)
                ans = t;
        }
        return ans;
    }
};
