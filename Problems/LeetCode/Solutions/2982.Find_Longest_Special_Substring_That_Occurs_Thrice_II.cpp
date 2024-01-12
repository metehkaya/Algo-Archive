class Solution {
public:
    int maximumLength(string s) {
        int n = s.length();
        map<int,int> mp[26];
        for( int i = 0 , j = 0 ; i < n ; i = j ) {
            while(j < n and s[i] == s[j])
                j++;
            int c = s[i]-'a' , k = j-i;
            mp[c][k]++;
            if(k-1 >= 1)
                mp[c][k-1] += 2;
            if(k-2 >= 1)
                mp[c][k-2] += 3;
        }
        int ans = -1;
        for( int i = 0 ; i < 26 ; i++ )
            for(auto it : mp[i])
                if(it.second >= 3)
                    ans = max(ans,it.first);
        return ans;
    }
};
