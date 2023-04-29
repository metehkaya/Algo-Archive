class Solution {
public:
    int dir[4] = {0,1,0,-1};
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& ar, vector<int>& p, vector<int>& start, int k) {
        vector<vector<int>> allItems;
        int n = ar.size() , m = ar[0].size();
        vector<vector<int>> dist(n,vector<int>(m,-1));
        queue<vector<int>> q;
        q.push(start);
        dist[start[0]][start[1]] = 0;
        while(!q.empty()) {
            vector<int> curr = q.front();
            q.pop();
            int r = curr[0] , c = curr[1];
            if(ar[r][c] >= p[0] && ar[r][c] <= p[1])
                allItems.push_back({dist[r][c],ar[r][c],r,c});
            for( int i = 0 ; i < 4 ; i++ ) {
                int r2 = r + dir[i];
                int c2 = c + dir[i^1];
                if(r2 < 0 || r2 >= n || c2 < 0 || c2 >= m)
                    continue;
                if(ar[r2][c2] == 0 || dist[r2][c2] != -1)
                    continue;
                q.push({r2,c2});
                dist[r2][c2] = dist[r][c]+1;
            }
        }
        sort(allItems.begin(),allItems.end());
        int sz = min((int)allItems.size(),k);
        allItems.resize(sz);
        vector<vector<int>> ans;
        for( int i = 0 ; i < sz ; i++ )
            ans.push_back({allItems[i][2],allItems[i][3]});
        return ans;
    }
};
