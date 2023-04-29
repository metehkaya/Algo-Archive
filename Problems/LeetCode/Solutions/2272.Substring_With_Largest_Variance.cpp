class Solution {
public:
    int largestVariance(string s) {
        int n = s.length();
        int ans = 0;
        int diff_arr[n+1];
        for( int a = 0 ; a < 26 ; a++ )
            for( int b = 0 ; b < 26 ; b++ )
                if(a != b) {
                    int diff = 0;
                    int last_a = -1, last_b = -1;
                    int last = -1;
                    diff_arr[0] = 0;
                    int mn = INT_MAX;
                    for( int i = 0 ; i < n ; i++ ) {
                        if(s[i] == 'a'+a || s[i] == 'a'+b) {
                            if(s[i] == 'a'+a) {
                                diff++;
                                last_a = i;
                            }
                            else {
                                diff--;
                                last_b = i;
                            }
                            int new_last = min(last_a,last_b);
                            if(new_last != -1) {
                                for( int i = last+1 ; i <= new_last ; i++ )
                                    mn = min(mn,diff_arr[i]);
                                last = new_last;
                                ans = max(ans,diff-mn);
                            }
                        }
                        diff_arr[i+1] = diff;
                    }
                }
        return ans;
    }
};
