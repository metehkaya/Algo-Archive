class Solution {
public:
    int numberOfSubarrays(vector<int>& ar, int k) {
        int n = ar.size();
        vector<int> v;
        for( int i = 0 ; i < n ; i++ )
            if(ar[i] % 2)
                v.push_back(i);
        int ans = 0;
        int m = v.size();
        for( int i = 0 ; i <= m - k ; i++ ) {
            int j = i+k-1;
            int left = (i == 0) ? v[0]+1 : v[i] - v[i-1];
            int right = (j == m-1) ? n-v[j] : v[j+1] - v[j];
            ans += left*right;
        }
        return ans;
    }
};