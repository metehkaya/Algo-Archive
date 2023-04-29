class Solution {
public:
    string baseNeg2(int n) {
        if(n == 0)
            return "0";
        string ans = "";
        while(n) {
            int r = abs(n)%2;
            n -= r;
            int q = -n/2;
            ans.push_back('0'+r);
            n = q;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};