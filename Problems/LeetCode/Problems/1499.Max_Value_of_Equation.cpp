class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& ar, int k) {
        int ans = INT_MIN;
        int n = ar.size();
        multiset<int> s;
        for( int i = 0 , j = 0 ; i < n ; i++ ) {
            if(i == j)
                j++;
            else
                s.erase(s.find(ar[i][0]+ar[i][1]));
            while(j < n && ar[j][0] - ar[i][0] <= k)
                s.insert(ar[j][0] + ar[j++][1]);
            if(!s.empty()) {
                auto it = s.end();
                it--;
                ans = max( ans , (*it) + ar[i][1] - ar[i][0] );
            }
        }
        return ans;
    }
};