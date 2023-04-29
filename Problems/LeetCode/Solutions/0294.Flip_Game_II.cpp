class Solution {
public:
    bool canWin(string s) {
        int n = s.length() , ans = 0;
        if(n <= 1)
            return false;
        vector<int> res(n+1,0);
        for( int i = 2 ; i <= n ; i++ ) {
            vector<int> v;
            for( int j = 0 ; j <= i-2 ; j++ )
                v.push_back(res[j]^res[i-2-j]);
            sort(v.begin(),v.end());
            int sz = v.size();
            int k = 0;
            while(k < sz) {
                bool ok = false;
                while(k < sz && v[k] == res[i])
                    k++ , ok = true;
                if(!ok)
                    break;
                res[i]++;
            }
        }
        for( int i = 0 , j = 0 ; i < n ; i = j ) {
            while(j < n && s[i] == s[j])
                j++;
            if(s[i] == '+')
                ans ^= res[j-i];
        }
        return ans > 0;
    }
};