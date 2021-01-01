class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& ar) {
        int n = ar.size() , total = 0;
        for( int i = 0 ; i < n ; i++ )
            total += ar[i];
        if(abs(total) % 3)
            return false;
        int target = total / 3;
        int l = n , r = -1;
        for( int i = 0 , sum = 0 ; i < n ; i++ ) {
            sum += ar[i];
            if(sum == target) {
                l = i;
                break;
            }
        }
        for( int i = n-1 , sum = 0 ; i >= 0 ; i-- ) {
            sum += ar[i];
            if(sum == target) {
                r = i;
                break;
            }
        }
        return l+1 < r;
    }
};