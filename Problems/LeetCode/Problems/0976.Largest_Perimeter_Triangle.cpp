class Solution {
public:
    int largestPerimeter(vector<int>& ar) {
        int n = ar.size();
        sort(ar.begin(),ar.end());
        for( int i = n-1 ; i >= 2 ; i-- )
            if(ar[i] < ar[i-1] + ar[i-2])
                return ar[i-2] + ar[i-1] + ar[i];
        return 0;
    }
};