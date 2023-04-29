class Solution {
public:
    long long appealSum(string s) {
        int n = s.length();
        vector<int>::iterator it;
        vector<int> occ[26];
        vector<int> idx(26,0);
        for( int i = 0 ; i < n ; i++ )
            occ[s[i]-'a'].push_back(i);
        long long ans = 0;
        for( int i = 0 ; i < n ; i++ ) {
            vector<int> v(1,n);
            for( int k = 0 ; k < 26 ; k++ )
                if(idx[k] != occ[k].size())
                    v.push_back(occ[k][idx[k]]);
            sort(v.begin(),v.end());
            int sz = v.size();
            for( int i = 0 ; i < sz-1 ; i++ )
                ans += (long long) (i+1) * (v[i+1]-v[i]);
            idx[s[i]-'a']++;
        }
        return ans;
    }
};
