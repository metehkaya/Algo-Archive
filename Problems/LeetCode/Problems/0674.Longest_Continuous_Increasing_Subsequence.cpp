class Solution {
public:
    int findLengthOfLCIS(vector<int>& ar) {
        int n = ar.size() , ans = 0;
        for( int i = 0 , j = 0 ; i < n ; i = j ) {
            j++;
            while(j < n && ar[j-1] < ar[j])
                j++;
            ans = max(ans,j-i);
        }
        return ans;
    }
};