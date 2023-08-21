class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.length() , m = t.length();
        for( int i = 0 , j = 0 ; j < m ; j++ ) {
            int exp1 = t[j]-'a';
            int exp2 = (exp1-1+26) % 26;
            bool found = false;
            do {
                int val = s[i]-'a';
                if(val == exp1 or val == exp2)
                    found = true;
                i++;
            }while(i < n and !found);
            if(!found)
                return false;
        }
        return true;
    }
};
