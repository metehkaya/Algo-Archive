class Solution {
public:
    int arrayPairSum(vector<int>& ar) {
        int n = ar.size() , sum = 0;
        sort(ar.begin(),ar.end());
        for( int i = 0 ; i < n ; i += 2 )
            sum += ar[i];
        return sum;
    }
};