class Solution {
public:
    int binaryGap(int n) {
        int ans = 0 , cnt = 0 , last = -1;
        while(n) {
            int x = n%2;
            if(x == 1) {
                if(last != -1)
                    ans = max(cnt-last,ans);
                last = cnt;
            }
            n /= 2;
            cnt++;
        }
        return ans;
    }
};