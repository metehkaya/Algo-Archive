class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& ar) {
        int n = ar.size() , ans = 0;
        sort(ar.begin() , ar.end() , [&](vector<int>& a , vector<int>& b) {
            return a[0] > b[0];
        });
        int mx = INT_MIN;
        for( int i = 0 , j = 0 ; i < n ; i = j ) {
            while(j < n && ar[i][0] == ar[j][0]) {
                if(ar[j][1] < mx)
                    ans++;
                j++;
            }
            for( int k = i ; k < j ; k++ )
                mx = max(mx,ar[k][1]);
        }
        return ans;
    }
};