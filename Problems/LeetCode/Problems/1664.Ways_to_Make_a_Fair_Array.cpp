class Solution {
public:
    int waysToMakeFair(vector<int>& ar) {
        int n = ar.size();
        vector<int> suml(n+1,0);
        vector<int> sumr(n+1,0);
        for (int i = 0; i < n; ++i) {
            suml[i+1] = ar[i]-suml[i];
            sumr[i+1] = ar[n-1-i]-sumr[i];
        }
        int ans = 0;
        for( int i = 0 ; i < n ; i++ )
            if(suml[i] == sumr[n-1-i])
                ans++;
        return ans;
    }
};