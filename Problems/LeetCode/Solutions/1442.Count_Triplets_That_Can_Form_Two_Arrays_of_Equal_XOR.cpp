class Solution {
public:
    int countTriplets(vector<int>& ar) {
        int n = ar.size();
        int ans = 0;
        for( int i = 0 ; i < n ; i++ ) {
            int val = ar[i];
            for( int j = i+1 ; j < n ; j++ ) {
                val ^= ar[j];
                if(val == 0)
                    ans += j-i;
            }
        }
        return ans;
    }
};