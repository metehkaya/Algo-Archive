class Solution {
public:
    int countKDifference(vector<int>& ar, int k) {
        int n = ar.size() , ans = 0;
        for( int i = 0 ; i < n ; i++ )
            for( int j = i+1 ; j < n ; j++ )
                if(abs(ar[i]-ar[j]) == k)
                    ans++;
        return ans;
    }
};