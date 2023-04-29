class Solution {
public:
    int convertTime(string s, string t) {
        int x = 60*(10*(s[0]-'0')+s[1]-'0') + (10*(s[3]-'0')+s[4]-'0');
        int y = 60*(10*(t[0]-'0')+t[1]-'0') + (10*(t[3]-'0')+t[4]-'0');
        if(y < x)
            y += 1440;
        int ans = 0;
        int add[4] = {60,15,5,1};
        for( int i = 0 ; i < 4 ; i++ ) {
            int cnt = (y-x)/add[i];
            ans += cnt;
            x += cnt*add[i];
        }
        return ans;
    }
};
