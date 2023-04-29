class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> perm(n);
        for( int i = 0 ; i < n ; i++ )
            perm[i] = i;
        int ans = 0;
        vector<int> fin = perm;
        while(true) {
            ans++;
            vector<int> ar(n);
            for( int i = 0 ; i < n ; i++ )
                if(i % 2 == 0)
                    ar[i] = perm[i/2];
                else
                    ar[i] = perm[n/2+i/2];
            perm = ar;
            if(perm == fin)
                break;
        }
        return ans;
    }
};