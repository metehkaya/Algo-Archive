class Solution {
public:
    int maxDifference(string s) {
        int odd = 0 , even = INT_MAX;
        map<char,int> mp;
        for(char c : s)
            mp[c]++;
        for(auto it : mp) {
            int cnt = it.second;
            if(cnt % 2 == 0)
                even = min(even,cnt);
            else
                odd = max(odd,cnt);
        }
        return odd - even;
    }
};