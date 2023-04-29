class Solution {
public:
    int minPatches(vector<int>& ar, int n) {
        int ans = 0;
        int m = ar.size();
        long long sum = 0;
        for( int i = 0 ; sum < n && i < m ; i++ ) {
            while(sum < n && ar[i] > sum+1) {
                ans++;
                sum += sum+1;
            }
            sum += ar[i];
        }
        while(sum < n) {
            ans++;
            sum += sum+1;
        }
        return ans;
    }
};