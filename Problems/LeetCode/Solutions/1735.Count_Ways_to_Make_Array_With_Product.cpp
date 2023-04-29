typedef long long LL;

class Solution {
public:
    const int mod = (int) 1e9+7;
    const static int maxc1 = 10020;
    const static int maxc2 = 20;
    int comb[maxc1][maxc2];
    int primes[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    vector<int> waysToFillArray(vector<vector<int>>& q) {
        for( int i = 0 ; i < maxc1 ; i++ )
            comb[i][0] = 1;
        for( int i = 1 ; i < maxc1 ; i++ )
            for( int j = 1 ; j < maxc2 ; j++ )
                comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % mod;
        vector<int> ans;
        for( int tc = 0 ; tc < q.size() ; tc++ ) {
            int g = q[tc][0];
            int n = q[tc][1];
            vector<int> v;
            for( int i = 0 ; i < 25 ; i++ )
                if(n % primes[i] == 0) {
                    int cnt = 0;
                    while(n % primes[i] == 0)
                        cnt++ , n /= primes[i];
                    v.push_back(cnt);
                }
            if(n > 1)
                v.push_back(1);
            LL res = 1;
            for( int i = 0 ; i < v.size() ; i++ ) {
                int cnt = v[i];
                int a = cnt + g-1;
                int b = cnt;
                LL mult = comb[a][b];
                res = (res * mult) % mod;
            }
            ans.push_back(res);
        }
        return ans;
    }
};