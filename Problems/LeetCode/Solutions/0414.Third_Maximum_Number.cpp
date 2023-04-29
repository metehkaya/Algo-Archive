class Solution {
public:
    int thirdMax(vector<int>& ar) {
        long long best1 = (long long) INT_MIN - 1;
        long long best2 = (long long) INT_MIN - 2;
        long long best3 = (long long) INT_MIN - 3;
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ ) {
            int x = ar[i];
            if(x > best1) {
                best3 = best2;
                best2 = best1;
                best1 = x;
            }
            else if(x > best2 && x < best1) {
                best3 = best2;
                best2 = x;
            }
            else if(x > best3 && x < best2)
                best3 = x;
        }
        return (best3 < INT_MIN) ? best1 : best3;
    }
};