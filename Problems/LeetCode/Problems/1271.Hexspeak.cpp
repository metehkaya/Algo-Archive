typedef long long LL;

class Solution {
public:
    string toHexspeak(string num) {
        LL value = 0;
        int len = num.length();
        for( int i = 0 ; i < len ; i++ )
            value = value * 10 + (num[i] - '0');
        string ans = "";
        while(value) {
            int digit = value % 16;
            value /= 16;
            if(digit >= 2 && digit <= 9)
                return "ERROR";
            if(digit == 0)
                ans.push_back('O');
            else if(digit == 1)
                ans.push_back('I');
            else
                ans.push_back('A'+(digit-10));
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};