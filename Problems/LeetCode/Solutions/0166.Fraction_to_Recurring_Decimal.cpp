class Solution {
public:
    string fractionToDecimal(int num, int den) {
        if(num == 0)
            return "0";
        string ans = "";
        if((num > 0 and den < 0) or (num < 0 and den > 0))
            ans.push_back('-');
        long long p = labs(num), q = labs(den);
        long long res = p/q;
        ans += to_string(res);
        long long r = p%q;
        if(r == 0)
            return ans;
        ans.push_back('.');
        unordered_map<int,int> mp;
        mp[r] = ans.length();
        while(r) {
            r *= 10;
            res = r/q;
            ans += to_string(res);
            r %= q;
            if(mp.find(r) != mp.end()) {
                ans.insert(ans.begin()+mp[r], '(');
                ans.push_back(')');
                break;
            }
            mp[r] = ans.length();
        }
        return ans;
    }
};
