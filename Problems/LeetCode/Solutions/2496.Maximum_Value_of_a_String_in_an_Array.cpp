class Solution {
public:
    bool check(string& s) {
        for(char c : s)
            if(!isdigit(c))
                return false;
        return true;
    }
    int maximumValue(vector<string>& strs) {
        int ans = 0;
        for(string s : strs)
            if(check(s))
                ans = max(ans,stoi(s));
            else
                ans = max(ans,(int)s.length());
        return ans;
    }
};
