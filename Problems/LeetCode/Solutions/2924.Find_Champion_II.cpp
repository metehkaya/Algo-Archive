class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indeg(n,0);
        for(auto& e : edges)
            indeg[e[1]]++;
        int ans = -1;
        for( int i = 0 ; i < n ; i++ )
            if(!indeg[i]) {
                if(ans == -1)
                    ans = i;
                else
                    return -1;
            }
        return ans;
    }
};
