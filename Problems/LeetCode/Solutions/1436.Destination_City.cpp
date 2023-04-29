class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        set<string> srcs;
        int n = paths.size();
        for( int i = 0 ; i < n ; i++ )
            srcs.insert(paths[i][0]);
        for( int i = 0 ; i < n ; i++ )
            if( srcs.find( paths[i][1] ) == srcs.end() )
                return paths[i][1];
        return "";
    }
};