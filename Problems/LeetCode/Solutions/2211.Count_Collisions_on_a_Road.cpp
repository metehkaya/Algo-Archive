class Solution {
public:
    int countCollisions(string s) {
        int r = 0 , ans = 0;
        bool steady = false;
        for(char c : s) {
            if(c == 'R') {
                r++;
                steady = false;
            }
            else if(c == 'S') {
                ans += r;
                r = 0;
                steady = true;
            }
            else {
                if(steady)
                    ans++;
                else if(r > 0) {
                    ans += r+1;
                    r = 0;
                    steady = true;
                }
            }
        }
        return ans;
    }
};
