class Solution {
public:
    int cnt[26][26];
    long long distinctNames(vector<string>& ar) {
        int n = ar.size();
        long long ans = 0;
        map<string,int> mp;
        for( int i = 0 ; i < n ; i++ ) {
            string s = ar[i];
            int len = s.length();
            string t = s.substr(1,len-1);
            int c = s[0]-'a';
            mp[t] |= (1<<c);
        }
        map<string,int>::iterator it;
        for( it = mp.begin() ; it != mp.end() ; it++ ) {
            vector<int> v[2];
            int val = (*it).second;
            for( int i = 0 ; i < 26 ; i++ ) {
                bool exists = ((val & (1<<i)) > 0);
                v[exists].push_back(i);
            }
            for( int i = 0 ; i < v[1].size() ; i++ )
                for( int j = 0 ; j < v[0].size() ; j++ )
                    ans += cnt[v[0][j]][v[1][i]];
            for( int i = 0 ; i < v[1].size() ; i++ )
                for( int j = 0 ; j < v[0].size() ; j++ )
                    cnt[v[1][i]][v[0][j]]++;
        }
        return 2*ans;
    }
};
