class Solution {
public:
    int minCost(string s, vector<int>& ar) {
        int n = s.length() , ans = 0;
        for( int i = 0 , j = 0 ; i < n ; i = j ) {
            while(j < n && s[i] == s[j])
                j++;
            if(j > i+1) {
                int mx = INT_MIN , all = 0;
                for( int k = i ; k < j ; k++ ) {
                    all += ar[k];
                    mx = max(mx,ar[k]);
                }
                ans += all-mx;
            }
        }
        return ans;
    }
};