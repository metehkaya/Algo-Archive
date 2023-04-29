class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string mx = s , mn = s;
        char c_min = s[0] , c_max;
        for(auto c : s)
            if(c != '9') {
                c_max = c;
                break;
            }
        for(auto& c : mx)
            if(c == c_max)
                c = '9';
        for(auto& c : mn)
            if(c == c_min)
                c = '0';
        return stoi(mx)-stoi(mn);
    }
};
