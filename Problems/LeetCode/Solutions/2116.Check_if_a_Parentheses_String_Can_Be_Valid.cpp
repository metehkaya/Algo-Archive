class Solution {
public:
    bool check(string& s , string& locked, int a , int b) {
        int change = 0 , curr = 0;
        int n = s.length();
        for( int i = 0 ; i < n ; i++ ) {
            if(locked[i] == '1') {
                if(s[i] == '(')
                    curr += a;
                else
                    curr += b;
                if(curr < 0 && change < -curr)
                    return false;
            }
            else
                change++;
        }
        return true;
    }
    bool canBeValid(string s_rev, string locked_rev) {
        if(s_rev.length() % 2)
            return false;
        string s = s_rev;
        string locked = locked_rev;
        reverse(s_rev.begin(), s_rev.end());
        reverse(locked_rev.begin(), locked_rev.end());
        return check(s,locked,+1,-1) && check(s_rev,locked_rev,-1,+1);
    }
};
