class Solution {
public:
    int calculate(string s) {
        s.push_back(' ');
        vector<char> ops;
        vector<int> nums;
        int n = s.length();
        for( int i = 0 , num = -1 ; i < n ; i++ ) {
            if(s[i] >= '0' && s[i] <= '9') {
                num = max(num,0);
                num *= 10;
                num += s[i]-'0';
            }
            else {
                if(num != -1)
                    nums.push_back(num);
                num = -1;
                if(s[i] != ' ')
                    ops.push_back(s[i]);
            }
        }
        n = ops.size();
        deque<int> Qnums;
        deque<char> Qops;
        Qnums.push_back(nums[0]);
        for( int i = 0 ; i < n ; i++ ) {
            char op = ops[i];
            int num = nums[i+1];
            if(op == '+' || op == '-') {
                Qops.push_back(op);
                Qnums.push_back(num);
            }
            else {
                int bef = Qnums.back();
                Qnums.pop_back();
                if(op == '*')
                    Qnums.push_back(bef*num);
                else
                    Qnums.push_back(bef/num);
            }
        }
        int ans = Qnums.front();
        Qnums.pop_front();
        while(!Qops.empty()) {
            char c = Qops.front();
            Qops.pop_front();
            int num = Qnums.front();
            Qnums.pop_front();
            if(c == '+')
                ans += num;
            else
                ans -= num;
        }
        return ans;
    }
};