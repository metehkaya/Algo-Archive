class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        int n = s.length() , m = chars.length();
        map<char,int> mp;
        for( int i = 0 ; i < m ; i++ )
            mp[chars[i]] = vals[i];
        vector<int> v;
        int ans = 0 , curr = 0;
        for( int i = 0 ; i < n ; i++ ) {
            int val;
            if(mp.count(s[i]))
                val = mp[s[i]];
            else
                val = s[i]-'a'+1;
            curr = max(curr+val,0);
            ans = max(ans,curr);
        }
        return ans;
    }
};
