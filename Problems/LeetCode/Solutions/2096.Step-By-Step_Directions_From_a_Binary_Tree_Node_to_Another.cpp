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
    static const int maxn = 100003;
    int t;
    int l[maxn];
    int r[maxn];
    int lsz[maxn];
    int rsz[maxn];
    int dt[maxn];
    int ft[maxn];
    int par[maxn];
    void dfs(TreeNode* node , int dad) {
        int u = node->val;
        par[u] = dad;
        dt[u] = ++t;
        if(node->left) {
            l[u] = node->left->val;
            dfs(node->left,u);
            lsz[u] = t-dt[u];
        }
        if(node->right) {
            r[u] = node->right->val;
            dfs(node->right,u);
            rsz[u] = t-dt[u]-lsz[u];
        }
        ft[u] = t;
    }
    string getDirections(TreeNode* root, int s, int f) {
        dfs(root,-1);
        string ans = "";
        while(ft[s] < dt[f] || ft[f] < dt[s]) {
            ans.push_back('U');
            s = par[s];
        }
        while(dt[f] <= dt[s] && ft[s] <= ft[f] && s != f) {
            ans.push_back('U');
            s = par[s];
        }
        while(s != f) {
            int left = l[s];
            int right = r[s];
            int ldt = dt[s]+1;
            int lft = ldt+lsz[s]-1;
            int rft = ft[s];
            int rdt = rft-rsz[s]+1;
            if(ldt <= dt[f] && ft[f] <= lft) {
                ans.push_back('L');
                s = l[s];
            }
            else {
                ans.push_back('R');
                s = r[s];
            }
        }
        return ans;
    }
};
