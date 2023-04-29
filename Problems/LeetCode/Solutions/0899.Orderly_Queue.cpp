class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k > 1) {
            sort(s.begin(),s.end());
            return s;
        }
        int n = s.length();
        string ans = s;
        for( int i = 1 ; i < n ; i++ ) {
            string t = s.substr(i) + s.substr(0,i);
            if(t < ans)
                ans = t;
        }
        return ans;
    }
};