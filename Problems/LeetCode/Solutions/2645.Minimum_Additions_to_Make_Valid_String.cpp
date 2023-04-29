class Solution {
public:
    int addMinimum(string s) {
        int n = s.length();
        int ans = (s[0]-'a') + ('c'-s[n-1]);
        for( int i = 1 ; i < n ; i++ ) {
            int c1 = s[i-1]-'a';
            int c2 = s[i]-'a';
            if(c1 == c2)
                ans += 2;
            else if(c2 != (c1+1)%3)
                ans++;
        }
        return ans;
    }
};
