class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string t) {
        vector<bool> ans;
        for( int w = 0 ; w < queries.size() ; w++ ) {
            string s = queries[w];
            int n = s.length();
            int m = t.length();
            bool ok = true;
            int i,j;
            for( i = 0 , j = 0 ; ok && j < m ; i++ , j++ ) {
                while(i < n && s[i] != t[j]) {
                    if(s[i] >= 'A' && s[i] <= 'Z') {
                        ok = false;
                        break;
                    }
                    i++;
                }
                if(i == n)
                    ok = false;
            }
            while(ok && i < n) {
                if(s[i] >= 'A' && s[i] <= 'Z')
                    ok = false;
                i++;
            }
            ans.push_back(ok);
        }
        return ans;
    }
};