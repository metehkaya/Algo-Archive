class Solution {
public:
    int triangleNumber(vector<int>& ar) {
        sort(ar.begin(),ar.end());
        int n = ar.size() , ans = 0;
        for( int i = 0 ; i < n ; i++ )
            for( int j = i+1 , idx = i+2 ; j < n-1 ; j++ ) {
                idx = max(idx,j+1);
                while(idx < n && ar[idx] < ar[i]+ar[j])
                    idx++;
                ans += idx-1-j;
            }
        return ans;
    }
};