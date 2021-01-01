class Solution {
public:
    int f(vector<int>& ar , int parity) {
        int n = ar.size() , sum = 0;
        for( int i = 0 ; i < n ; i++ )
            if(i%2 == parity) {
                int mn = INT_MAX;
                if(i>0)
                    mn = ar[i-1];
                if(i<n-1)
                    mn = min(mn,ar[i+1]);
                sum += max(ar[i]-(mn-1),0);
            }
        return sum;
    }
    int movesToMakeZigzag(vector<int>& ar) {
        return min( f(ar,0) , f(ar,1) );
    }
};