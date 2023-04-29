class Solution {
public:
    int ans=0;
    string low,high;
    vector<pair<string,string>> v = {{"0","0"},{"1","1"},{"6","9"},{"8","8"},{"9","6"}};
    bool lteq(string& s , string& t) {
        return s.length() < t.length() or (s.length() == t.length() and s <= t);
    }
    void f(string s) {
        if(!s.empty()) {
            if(!lteq(s,high))
                return;
            if((s == "0" or s[0] != '0') and lteq(low,s))
                ans++;
        }
        for(auto p : v)
            f(p.first + s + p.second);
    }
    int strobogrammaticInRange(string low, string high) {
        this->low = low;
        this->high = high;
        f("");
        f("0");
        f("1");
        f("8");
        return ans;
    }
};
