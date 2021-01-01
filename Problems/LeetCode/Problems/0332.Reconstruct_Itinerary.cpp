class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& edges) {
        map<string,int> index;
        map<string,vector<string>> adj;
        int m = edges.size();
        for( int i = 0 ; i < m ; i++ ) {
            string s = edges[i][0];
            string e = edges[i][1];
            adj[s].push_back(e);
        }
        for( auto it = adj.begin() ; it != adj.end() ; it++ )
            sort(it->second.begin(),it->second.end());
        vector<string> ans;
        dfs("JFK",adj,index,ans);
        reverse(ans.begin() , ans.end());
        return ans;
    }
    void dfs(string city , map<string,vector<string>>& adj , map<string,int>& index , vector<string>& ans) {
        while(index[city] < adj[city].size()) {
            string to = adj[city][index[city]++];
            dfs(to,adj,index,ans);
        }
        ans.push_back(city);
    }
};