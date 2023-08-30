class Solution {
public:
    pair<int, int> calculate(string& s) {
        int coefficient = 0, constant = 0;
        int num = 0, sign = 1;;
        for( int i = 0 ; i < s.length() ; i++ ) {
            char c = s[i];
            if(isdigit(c))
                num = 10*num + c-'0';
            else if(c == '+' or c == '-') {
                constant += sign * num;
                sign = c == '+' ? 1 : -1;
                num = 0;
            }
            else {
                if(i > 0 and num == 0 and s[i-1] == '0')
                    continue;
                coefficient += num == 0 ? sign : sign * num;
                num = 0;
            }
        }
        constant += sign * num;
        return make_pair(coefficient, constant);
    }
    string solveEquation(string str) {
        int idx = str.find('=');
        string s = str.substr(0, idx);
        string t = str.substr(idx+1);
        pair<int,int> l = calculate(s);
        pair<int,int> r = calculate(t);
        int coefficient = l.first - r.first;
        int constant = r.second - l.second;
        if(coefficient == 0 and constant == 0)
            return "Infinite solutions";
        if(coefficient == 0 and constant != 0)
            return "No solution";
        return "x=" + to_string(constant / coefficient);
    }
};
