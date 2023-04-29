class Solution {
public:
    int countQuadruplets(vector<int>& ar) {
        int n = ar.size() , ans = 0;
        for( int i = 0 ; i < n ; i++ )
            for( int j = i+1 ; j < n ; j++ )
                for( int k = j+1 ; k < n ; k++ )
                    for( int l = k+1 ; l < n ; l++ )
                        if(ar[i]+ar[j]+ar[k] == ar[l])
                            ans++;
        return ans;
    }
};