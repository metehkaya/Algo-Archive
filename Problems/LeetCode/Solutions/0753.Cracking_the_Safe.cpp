class Solution {
public:
    string crackSafe(int n, int k) {
        string ans = "";
        int rem = 1;
        for( int i = 0 ; i < n ; i++ )
            ans.push_back('0') , rem *= k;
        set<string> s;
        s.insert(ans);
        int len = n;
        while(--rem) {
            string prefix = ans.substr(len-(n-1),n-1);
            for( int i = k-1 ; i >= 0 ; i-- ) {
                char c = '0' + i;
                string t = prefix + c;
                if(s.find(t) == s.end()) {
                    ans.push_back(c);
                    s.insert(t);
                    len++;
                    break;
                }
            }
        }
        return ans;
    }
};
