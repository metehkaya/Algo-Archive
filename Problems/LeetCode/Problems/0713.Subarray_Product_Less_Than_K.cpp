class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& ar, int k) {
        int n = ar.size() , ans = 0;
        for( int i = 0 , j = 0 , mult = 1 ; i < n ; i++ ) {
            j = max(j,i);
            if(i)
                mult /= ar[i-1];
            while(j < n && mult < k)
                mult *= ar[j++];
            if(mult < k)
                ans += max(j-i,0);
            else
                ans += max(j-i-1,0);
        }
        return ans;
    }
};