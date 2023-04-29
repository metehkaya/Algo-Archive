class Solution {
public:
    int closestFair(int n) {
        while(true) {
            string s = to_string(n);
            int len = s.length();
            if(len % 2) {
                n = pow(10,len++);
                s = to_string(n);
            }
            int cnt_odd = 0;
            for(char c : s)
                cnt_odd += (c-'0')%2;
            if(cnt_odd == len/2)
                break;
            n++;
        }
        return n;
    }
};
