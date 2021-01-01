class Solution {
public:
    int missingElement(vector<int>& ar, int k) {
        int n = ar.size();
        for( int i = 0 ; i < n-1 ; i++ ) {
            int diff = ar[i+1]-ar[i]-1;
            if(k <= diff)
                return ar[i]+k;
            k -= diff;
        }
        return ar[n-1]+k;
    }
};