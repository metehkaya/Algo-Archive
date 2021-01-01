typedef vector<int> vi;
typedef vector<vi> vii;

class Solution {
public:
    void dfs(int u , int e , vii& graph , vi& curr , vii& ans) {
        if(u == e) {
            ans.push_back(curr);
            return;
        }
        for( int i = 0 ; i < graph[u].size() ; i++ ) {
            int v = graph[u][i];
            curr.push_back(v);
            dfs(v,e,graph,curr,ans);
            curr.pop_back();
        }
    }
    vii allPathsSourceTarget(vii& graph) {
        vii ans;
        vi curr(1,0);
        int n = graph.size();
        dfs(0,n-1,graph,curr,ans);
        return ans;
    }
};