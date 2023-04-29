class Solution {
public:
    string convertToTitle(int N) {
        long long n = N;
        vector<long long>pwr26;
        pwr26.push_back(1);
        int ind = 0;
        while(n > pwr26[ind]*26) {
            pwr26.push_back( pwr26[ind++]*26 );
            n -= pwr26[ind];
        }
        n--;
        string s = "";
        for( int i = ind ; i >= 0 ; i-- ) {
            int val = n / pwr26[i];
            n -= val * pwr26[i];
            char c = 'A' + val;
            s.push_back(c);
        }
        return s;
    }
};