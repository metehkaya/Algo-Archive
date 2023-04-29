class Solution {
public:
    int getID( string& region , map<string,int>& hashh , vector<int>& parent , vector<string>& allRegions , int& n ) {
        map<string,int>::iterator mit = hashh.find(region);
        if(mit == hashh.end()) {
            hashh[region] = n++;
            parent.push_back(-1);
            allRegions.push_back(region);
        }
        return hashh[region];
    }
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        int n = 0;
        vector<int> parent;
        map<string,int> hashh;
        vector<string> allRegions;
        for( int i = 0 ; i < regions.size() ; i++ ) {
            int dad = getID( regions[i][0] , hashh , parent , allRegions , n );
            for( int j = 1 ; j < regions[i].size() ; j++ ) {
                int child = getID( regions[i][j] , hashh , parent , allRegions , n );
                parent[child] = dad;
            }
        }
        int u = hashh[region1];
        int v = hashh[region2];
        set<int> path;
        while(parent[u] != -1) {
            path.insert(u);
            u = parent[u];
        }
        path.insert(u);
        while(path.find(v) == path.end())
            v = parent[v];
        return allRegions[v];
    }
};