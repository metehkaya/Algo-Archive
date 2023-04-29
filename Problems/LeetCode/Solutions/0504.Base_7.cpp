class Solution {
public:
    string convertToBase7(int num) {
        bool neg = false;
        if(num < 0) {
            neg = true;
            num = abs(num);
        }
        string ans = "";
        if(num == 0)
            ans = "0";
        else
            while(num) {
                ans.push_back('0'+(num%7));
                num /= 7;
            }
        reverse(ans.begin(),ans.end());
        if(neg)
            ans = "-" + ans;
        return ans;
    }
};