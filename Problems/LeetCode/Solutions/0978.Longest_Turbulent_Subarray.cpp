class Solution {
public:
    int maxTurbulenceSize(vector<int>& ar) {
        int n = ar.size();
        vector<int> a;
        for( int i = 0 ; i < n-1 ; i++ )
            if(ar[i] > ar[i+1])
                a.push_back(1);
            else if(ar[i] < ar[i+1])
                a.push_back(2);
            else
                a.push_back(0);
        n = a.size();
        int ans = 1;
        for( int i = 0 , j = 0 ; i < n ; i = j ) {
            if(a[i] == 0) {
                j++;
                continue;
            }
            while( j < n && ( (i%2 == j%2) == (a[i] == a[j]) ) && a[j] )
                j++;
            ans = max(ans,j-i+1);
        }
        return ans;
    }
};