class Solution {
public:
    int get_num(string& s , int& idx) {
        int val = 0;
        while(idx < s.length() and isdigit(s[idx]))
            val = 10*val + s[idx++]-'0';
        return val;
    }
    int f(string& s , int& idx) {
        vector<int> v;
        char op = '+';
        for( ; idx < s.length() and op != ')' ; idx++ ) {
            int val = (s[idx] == '(') ? f(s,++idx) : get_num(s,idx);
            switch(op) {
                case '+':
                    v.push_back(val);
                    break;
                case '-':
                    v.push_back(-val);
                    break;
                case '*':
                    v.back() *= val;
                    break;
                case '/':
                    v.back() /= val;
                    break;
            }
            op = s[idx];
        }
        int sum = 0;
        for(int x : v)
            sum += x;
        return sum;
    }
    int calculate(string s) {
        int idx = 0;
        return f(s,idx);
    }
};
