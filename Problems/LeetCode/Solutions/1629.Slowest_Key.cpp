class Solution {
public:
    int mx;
    char ans;
    char slowestKey(vector<int>& ar, string s) {
        int n = ar.size();
        ans = s[0];
        mx = ar[0];
        for( int i = 1 ; i < n ; i++ ) {
            char c = s[i];
            int dur = ar[i]-ar[i-1];
            if(dur > mx || (dur == mx && c > ans)) {
                ans = c;
                mx = dur;
            }
        }
        return ans;
    }
};