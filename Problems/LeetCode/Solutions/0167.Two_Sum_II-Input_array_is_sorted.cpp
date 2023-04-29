class Solution {
public:
    vector<int> twoSum(vector<int>& ar, int t) {
        int n = ar.size();
        vector<int> ans(2);
        for( int i = 0 ; i < n-1 ; i++ ) {
            int l = i+1 , r = n-1;
            while(l <= r) {
                int m = (l+r) >> 1;
                if(ar[i]+ar[m] < t)
                    l = m+1;
                else if(ar[i]+ar[m] > t)
                    r = m-1;
                else {
                    ans[0] = i+1;
                    ans[1] = m+1;
                    return ans;
                }
            }
        }
        return ans;
    }
};