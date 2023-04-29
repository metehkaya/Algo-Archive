typedef long long LL;

class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        int n = s.length() , idx = -1;
        LL curr = 0 , p = 1;
        for( int i = 1 ; i < k ; i++ )
            p = p*power % modulo;
        for( int i = n-1 ; i >= 0 ; i-- ) {
            curr = curr*power + (s[i]-'a'+1);
            curr %= modulo;
            if(i <=
               n-k) {
                if(curr == hashValue)
                    idx = i;
                curr -= p*(s[i+k-1]-'a'+1);
                curr %= modulo;
                if(curr < 0)
                    curr += modulo;
            }
        }
        return s.substr(idx,k);
    }
};
