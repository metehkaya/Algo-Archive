class Solution {
public:
    int maximumTop(vector<int>& ar, int k) {
        int n = ar.size();
        if(n == 1)
            return (k%2 == 1) ? -1 : ar[0];
        int ans = 0;
        for( int i = 0 ; i < n ; i++ )
            if(i == k || k >= i+2)
                ans = max(ans,ar[i]);
        return ans;
    }
};
