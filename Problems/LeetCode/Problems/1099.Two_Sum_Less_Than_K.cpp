class Solution {
public:
    int twoSumLessThanK(vector<int>& ar, int k) {
        int n = ar.size() , ans = -1;
        for( int i = 0 ; i < n ; i++ )
            for( int j = i+1 ; j < n ; j++ ) {
                int s = ar[i]+ar[j];
                if(s < k && s > ans)
                    ans = s;
            }
        return ans;
    }
};