class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        vector<int> costs(n);
        for( int i = 0 ; i < n ; i++ )
            costs[i] = abs(s[i] - t[i]);
        int ans = 0;
        for( int i = 0 , j = 0 , cost = 0 ; i < n ; i++ ) {
            if(i > 0 && i <= j)
                cost -= costs[i-1];
            if(j <= i)
                cost = 0 , j = i;
            while(j < n && cost + costs[j] <= maxCost)
                cost += costs[j++];
            ans = max(ans , j-i);
        }
        return ans;
    }
};