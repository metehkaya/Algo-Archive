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
    int n;
    TreeNode* ans;
    set<int> allNodes;
    int dfs(TreeNode* node) {
        int cnt = (allNodes.find(node->val) != allNodes.end());
        if(node->left)
            cnt += dfs(node->left);
        if(node->right)
            cnt += dfs(node->right);
        if(cnt == n && ans == NULL)
            ans = node;
        return cnt;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        n = nodes.size();
        for( int i = 0 ; i < n ; i++ )
            allNodes.insert(nodes[i]->val);
        ans = NULL;
        dfs(root);
        return ans;
    }
};