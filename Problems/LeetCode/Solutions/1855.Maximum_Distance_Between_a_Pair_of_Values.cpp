class Solution {
public:
    int maxDistance(vector<int>& a, vector<int>& b) {
        int ans = 0;
        int n = a.size();
        int m = b.size();
        for( int i = 0 , j = 0 ; i < n ; i++ ) {
            j = max(j,i);
            if(j == m)
                break;
            while(j+1 < m && a[i] <= b[j+1])
                j++;
            if(a[i] <= b[j])
                ans = max(ans,j-i);
        }
        return ans;
    }
};