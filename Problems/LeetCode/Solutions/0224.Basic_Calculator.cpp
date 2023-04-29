class Solution {
public:
    stack<int> nums,signs;
    int calculate(string s) {
        int n = s.length();
        int ans = 0 , sign = 1;
        for( int i = 0 ; i < n ; i++ ) {
            if(isdigit(s[i])) {
                int val = 0;
                while(isdigit(s[i])) {
                    val = 10*val + (s[i]-'0');
                    i++;
                }
                ans += sign * val;                    
                i--;
            }
            else if(s[i] == '+')
                sign =  1;
            else if(s[i] == '-')
                sign = -1;
            else if(s[i] == '(') {
                nums.push(ans);
                signs.push(sign);
                ans = 0;
                sign = 1;
            }
            else if(s[i] == ')') {
                ans = ans * signs.top() + nums.top();
                nums.pop();
                signs.pop();
            }
        }
        return ans;
    }
};