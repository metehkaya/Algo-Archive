class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        int l = 0 , r = n-1;
        while(l < r) {
            int times = r-l+1;
            char c1 = s[l];
            char c2 = s[r];
            if(c1 != c2)
                break;
            while(l <= r && s[l] == c1)
                l++;
            while(l <= r && s[r] == c2)
                r--;
            if(l == r)
                return 1;
            if(l > r)
                return 0;
        }
        return r-l+1;
    }
};