class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& ar) {
        int n = ar.size();
        vector<int> diffs;
        for( int i = 1 ; i < n ; i++ )
            diffs.push_back(ar[i]-ar[i-1]);
        n--;
        int ans = 0;
        for( int i = 0 , j = 0 ; i < n ; i = j ) {
            while(j < n && diffs[i] == diffs[j])
                j++;
            int k = j-i;
            ans += k*(k-1)/2;
        }
        return ans;
    }
};