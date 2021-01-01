class Solution {
public:
    bool equationsPossible(vector<string>& ar) {
        vector<int> dad(26,-1);
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ )
            if(ar[i][1] == '=') {
                int u = ar[i][0]-'a';
                int v = ar[i][3]-'a';
                while(dad[u] != -1)
                    u = dad[u];
                while(dad[v] != -1)
                    v = dad[v];
                if(u != v)
                    dad[v] = u;
            }
        for( int i = 0 ; i < n ; i++ )
            if(ar[i][1] == '!') {
                int u = ar[i][0]-'a';
                int v = ar[i][3]-'a';
                while(dad[u] != -1)
                    u = dad[u];
                while(dad[v] != -1)
                    v = dad[v];
                if(u == v)
                    return false;
            }
        return true;
    }
};