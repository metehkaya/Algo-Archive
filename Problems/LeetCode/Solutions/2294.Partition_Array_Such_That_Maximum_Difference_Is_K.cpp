class Solution {
public:
    int partitionArray(vector<int>& ar, int k) {
        int n = ar.size() , ans = 0;
        sort(ar.begin(),ar.end());
        for( int i = 0 , j = 0 ; i < n ; i = j ) {
            ans++;
            while(j < n && ar[j]-ar[i] <= k)
                j++;
        }
        return ans;
    }
};
