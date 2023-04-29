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
    map<int,int> l,r,p;
    void dfs(TreeNode* node) {
        int val = node->val;
        if(l.find(val) != l.end()) {
            node->left = new TreeNode(l[val]);
            dfs(node->left);
        }
        if(r.find(val) != r.end()) {
            node->right = new TreeNode(r[val]);
            dfs(node->right);
        }
    }
    TreeNode* createBinaryTree(vector<vector<int>>& ar) {
        set<int> nodes;
        for( int i = 0 ; i < ar.size() ; i++ ) {
            int par = ar[i][0];
            int child = ar[i][1];
            int type = ar[i][2];
            nodes.insert(par);
            p[child] = par;
            if(type == 1)
                l[par] = child;
            else
                r[par] = child;
        }
        int r;
        for(int u : nodes)
            if(p.find(u) == p.end()) {
                r = u;
                break;
            }
        TreeNode* root = new TreeNode(r);
        dfs(root);
        return root;
    }
};
