class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& v) {
        int n = v.size();
        vector<int> l(n),r(n),ans(n);
        for( int i = 0 , sum = 0 ; i < n ; i++ ) {
            l[i] = sum;
            sum += v[i];
        }
        for( int i = n-1 , sum = 0 ; i >= 0 ; i-- ) {
            r[i] = sum;
            sum += v[i];
        }
        for( int i = 0 ; i < n ; i++ )
            ans[i] = abs(l[i]-r[i]);
        return ans;
    }
};
