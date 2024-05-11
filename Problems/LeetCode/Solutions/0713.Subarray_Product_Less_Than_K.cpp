class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& ar, int k) {
        int n = ar.size() , ans = 0 , mult = 1;
        for( int i = 0 , j = 0 , mult = 1 ; i < n ; i++ ) {
            if(j < i) {
                j = i;
                mult = 1;
            }
            else if(i)
                mult /= ar[i-1];
            while(j < n && mult*ar[j] < k)
                mult *= ar[j++];
            ans += j-i;
        }
        return ans;
    }
};
