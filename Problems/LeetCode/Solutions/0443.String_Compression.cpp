class Solution {
public:
    int compress(vector<char>& s) {
        int n = s.size() , ans = 0;
        for( int i = 0 , j = 0 ; i < n ; i = j ) {
            while(j < n && s[i] == s[j])
                j++;
            int diff = j-i;
            char c = s[i];
            s[ans++] = c;
            if(diff > 1) {
                string t = to_string(diff);
                int sz = t.length();
                for( int k = 0 ; k < sz ; k++ )
                    s[ans++] = t[k];
            }
        }
        return ans;
    }
};