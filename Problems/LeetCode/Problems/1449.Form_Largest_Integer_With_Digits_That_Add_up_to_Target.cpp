typedef vector<int> vi;
typedef vector<vi> vii;

class Solution {
public:
    const int K = 9;
    vector<int> getVec(vector<int>& cnt, int num) {
        vector<int> v;
        for( int i = 0 ; i < K ; i++ )
            v.push_back(cnt[i]);
        v[num]++;
        return v;
    }
    bool isBetter(vector<int>& a, vector<int>& b) {
        int suma = 0 , sumb = 0;
        for( int i = 0 ; i < K ; i++ )
            suma += a[i] , sumb += b[i];
        if(suma != sumb)
            return suma > sumb;
        for( int i = K-1 ; i >= 0 ; i-- )
            if( a[i] != b[i] )
                return a[i] > b[i];
        return false;
    }
    string largestNumber(vi& cost, int target) {
        vii dp(target+1);
        for( int i = 0 ; i < K ; i++ )
            dp[0].push_back(0);
        for( int i = 0 ; i < target ; i++ )
            if( !dp[i].empty() )
                for( int j = 0 ; j < K ; j++ )
                    if( i + cost[j] <= target ) {
                        vector<int> v = getVec(dp[i], j);
                        int nextCost = i + cost[j];
                        if(dp[nextCost].empty())
                            dp[nextCost] = v;
                        else if(isBetter(v, dp[nextCost]))
                            dp[nextCost] = v;
                    }
        string ans = "";
        if(dp[target].empty())
            ans = "0";
        else
            for( int i = K-1 ; i >= 0 ; i-- ) {
                char c = '0' + (i+1);
                for( int j = 0 ; j < dp[target][i] ; j++ )
                    ans.push_back(c);
            }
        return ans;
    }
};