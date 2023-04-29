class Solution {
public:
    int maxAscendingSum(vector<int>& ar) {
        int ans = 0;
        int n = ar.size();
        for( int i = 0 , j = 0 ; i < n ; i = j+1 ) {
            j = i;
            int sum = ar[i];
            while(j+1 < n && ar[j] < ar[j+1])
                sum += ar[++j];
            ans = max(ans,sum);
        }
        return ans;
    }
};