class Solution {
public:
    int findPoisonedDuration(vector<int>& ar, int d) {
        int n = ar.size() , ans = 0;
        for( int i = 0 , j = 0 ; i < n ; i = j ) {
            j++;
            while(j < n && ar[j-1]+d >= ar[j])
                j++;
            ans += ar[j-1]+d - ar[i];
        }
        return ans;
    }
};