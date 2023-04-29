struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    static const int maxn = 100001;
    int dist[maxn];
    vector<int> adj[maxn];
    void dfs(TreeNode* node , TreeNode* dad) {
        if(node == NULL)
            return;
        if(dad != NULL) {
            adj[dad->val].push_back(node->val);
            adj[node->val].push_back(dad->val);
        }
        dfs(node->left,node);
        dfs(node->right,node);
    }
    int amountOfTime(TreeNode* root, int s) {
        dfs(root,NULL);
        memset(dist,-1,sizeof(dist));
        queue<int> q;
        q.push(s);
        dist[s] = 0;
        int ans = 0;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            ans = dist[u];
            int deg = adj[u].size();
            for( int i = 0 ; i < deg ; i++ ) {
                int v = adj[u][i];
                if(dist[v] == -1) {
                    q.push(v);
                    dist[v] = dist[u]+1;
                }
            }
        }
        return ans;
    }
};
