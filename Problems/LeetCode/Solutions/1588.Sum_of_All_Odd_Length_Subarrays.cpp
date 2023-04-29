class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& ar) {
        int n = ar.size() , ans = 0;
        for( int i = 0 ; i < n ; i++ ) {
            int sum = 0;
            for( int j = i ; j < n ; j++ ) {
                sum += ar[j];
                if((j-i)%2 == 0)
                    ans += sum;
            }
        }
        return ans;
    }
};