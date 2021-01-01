class Solution {
public:
    int shortestWordDistance(vector<string>& words, string s, string t) {
        map<string,vector<int>> mp;
        int n = words.size();
        for( int i = 0 ; i < n ; i++ )
            mp[words[i]].push_back(i);
        vector<int> a = mp[s];
        vector<int> b = mp[t];
        int ans = n-1;
        int na = a.size();
        int nb = b.size();
        for( int i = 0 ; i < na ; i++ )
            for( int j = 0 ; j < nb ; j++ )
                if(a[i] != b[j])
                    ans = min( ans , abs( a[i]-b[j] ) );
        return ans;
    }
};