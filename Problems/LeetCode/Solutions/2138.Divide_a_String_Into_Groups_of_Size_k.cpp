class Solution {
public:
    vector<string> divideString(string s, int k, char f) {
        int n = s.length();
        vector<string> ans;
        for( int i = 0 ; i < n ; i += k ) {
            int j = min(i+k,n);
            string t = s.substr(i,j-i);
            int rem = k-t.length();
            while(rem--)
                t.push_back(f);
            ans.push_back(t);
        }
        return ans;
    }
};
