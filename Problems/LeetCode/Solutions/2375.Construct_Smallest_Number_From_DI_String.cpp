class Solution {
public:
    string smallestNumber(string s) {
        int n = s.length();
        vector<int> v(n+1);
        for( int i = 0 ; i <= n ; i++ )
            v[i] = i+1;
        string ans = "";
        do {
            bool ok = true;
            for( int i = 0 ; i < n ; i++ ) {
                if(s[i] == 'I' && v[i] > v[i+1])
                    ok = false;
                else if(s[i] == 'D' && v[i] < v[i+1])
                    ok = false;
            }
            if(ok) {
                for( int i = 0 ; i <= n ; i++ )
                    ans.push_back('0'+v[i]);
                break;
            }
        }while(next_permutation(v.begin(),v.end()));
        return ans;
    }
};
