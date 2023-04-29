class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans = 0;
        int n = g.size();
        int m = s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        for( int i = 0 , j = 0 ; i < n && j < m ; i++ ) {
            while(j < m && s[j] < g[i])
                j++;
            if(j < m)
                ans++,j++;
        }
        return ans;
    }
};