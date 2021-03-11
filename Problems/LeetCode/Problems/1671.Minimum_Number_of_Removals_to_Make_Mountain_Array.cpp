class Solution {
public:
    int minimumMountainRemovals(vector<int>& ar) {
        int n = ar.size();
        vector<int> prefix(n,1);
        for( int i = 1 ; i < n ; i++ )
            for( int j = 0 ; j < i ; j++ )
                if(ar[i] > ar[j])
                    prefix[i] = max(prefix[i] , prefix[j]+1);
        vector<int> suffix(n,1);
        for( int i = n-2 ; i >= 0 ; i-- )
            for( int j = i+1 ; j < n ; j++ )
                if(ar[i] > ar[j])
                    suffix[i] = max(suffix[i] , suffix[j]+1);
        int mx = 3;
        for( int i = 1 ; i < n-1 ; i++ )
            if(prefix[i] > 1 && suffix[i] > 1)
                mx = max(mx,prefix[i]+suffix[i]-1);
        return n-mx;
    }
};