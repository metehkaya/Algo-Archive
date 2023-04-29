class Solution {
public:
    int arithmeticTriplets(vector<int>& ar, int diff) {
        int ans = 0;
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ )
            for( int j = i+1 ; j < n ; j++ )
                if(ar[i]+diff == ar[j])
                    for( int k = j+1 ; k < n ; k++ )
                        if(ar[j]+diff == ar[k]) {
                            ans++;
                            break;
                        }
        return ans;
    }
};
