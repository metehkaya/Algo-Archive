class Solution {
public:
    int countPairs(vector<int>& ar, int k) {
        int n = ar.size() , ans = 0;
        for( int i = 0 ; i < n ; i++ )
            for( int j = i+1 ; j < n ; j++ )
                if(ar[i] == ar[j] && (i*j)%k == 0)
                    ans++;
        return ans;
    }
};
