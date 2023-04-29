class Solution {
public:
    long long getDescentPeriods(vector<int>& ar) {
        int n = ar.size();
        long long ans = 0;
        for( int i = 0 , j = 0 ; i < n ; i = j ) {
            while(j < n && ar[i]-ar[j] == j-i)
                j++;
            long long len = j-i;
            ans += len*(len+1)/2;
        }
        return ans;
    }
};
