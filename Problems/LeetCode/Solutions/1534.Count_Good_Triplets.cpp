class Solution {
public:
    int countGoodTriplets(vector<int>& ar, int a, int b, int c) {
        int n = ar.size() , ans = 0;
        for( int i = 0 ; i < n ; i++ )
            for( int j = i+1 ; j < n ; j++ )
                for( int k = j+1 ; k < n ; k++ )
                    if( abs(ar[i]-ar[j]) <= a && abs(ar[j]-ar[k]) <= b && abs(ar[i]-ar[k]) <= c )
                        ans++;
        return ans;
    }
};