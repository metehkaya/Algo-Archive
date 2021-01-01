class Solution {
public:
    int findNumbers(vector<int>& ar) {
        int ans = 0;
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ ) {
            int x = ar[i] , cnt = 0;
            while(x) {
                cnt++;
                x /= 10;
            }
            if(cnt % 2 == 0)
                ans++;
        }
        return ans;
    }
};