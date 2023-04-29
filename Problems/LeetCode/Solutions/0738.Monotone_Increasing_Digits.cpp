class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        if(n < 10)
            return n;
        int N = n;
        vector<int> v;
        while(n) {
            v.push_back(n%10);
            n /= 10;
        }
        reverse(v.begin(),v.end());
        int idx = -1;
        int sz = v.size();
        for( int i = 0 ; i < sz-1 ; i++ )
            if(v[i] > v[i+1]) {
                idx = i;
                break;
            }
        if(idx == -1)
            return N;
        int num = v[idx];
        while(idx >= 0 && v[idx] == num)
            idx--;
        v[++idx]--;
        for( int i = idx+1 ; i < sz ; i++ )
            v[i] = 9;
        for( int i = 0 ; i < sz ; i++ )
            n = 10*n + v[i];
        return n;
    }
};