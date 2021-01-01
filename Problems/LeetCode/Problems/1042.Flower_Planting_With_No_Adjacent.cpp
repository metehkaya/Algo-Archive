class Solution {
public:
    bool checkColor(int id, int& n, vector<int>& colors, vector< vector<int> >& adj, int color) {
        for( int i = 0 ; i < (int) adj[id].size() ; i++ )
            if(color == colors[adj[id][i]])
                return false;
        return true;
    }
    bool colorGraph(int id, int& n, vector<int>& colors, vector< vector<int> >& adj) {
        if(id == n)
            return true;
        for( int i = 1 ; i <= 4 ; i++ )
            if(checkColor(id,i,colors,adj,i)) {
                colors[id] = i;
                if(colorGraph(id+1,n,colors,adj))
                    return true;
                colors[id] = 0;
            }
        return false;
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        int m = paths.size();
        vector< vector<int> > adj(n);
        for( int i = 0 ; i < m ; i++ ) {
            int x = paths[i][0] - 1;
            int y = paths[i][1] - 1;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<int> colors(n,0);
        colorGraph(0,n,colors,adj);
        return colors;
    }
};