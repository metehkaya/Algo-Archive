class Solution {
public:
    int getTime(string& s) {
        int h = 10*(s[0]-'0')+s[1]-'0';
        int m = 10*(s[3]-'0')+s[4]-'0';
        return 60*h+m;
    }
    int numberOfRounds(string startTime, string finishTime) {
        int x = getTime(startTime);
        int y = getTime(finishTime);
        int ans = 0;
        if(x > y)
            ans = (1440-x)/15 + y/15;
        else if(y-x >= 15) {
            if(x % 15)
                x += 15 - x%15;
            if(y % 15)
                y -= y%15;
            ans = (y-x)/15;
        }
        return ans;
    }
};