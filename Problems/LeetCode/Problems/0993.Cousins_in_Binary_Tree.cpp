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
    bool dfs(TreeNode* node, int val, vector<int>& path) {
        if(node->val == val)
            return true;
        if(node->left && dfs(node->left, val, path)) {
            path.push_back(node->val);
            return true;
        }
        if(node->right && dfs(node->right, val, path)) {
            path.push_back(node->val);
            return true;
        }
        return false;
    }
    bool isCousins(TreeNode* root, int x, int y) {
        vector<int> pathX, pathY;
        dfs(root, x, pathX);
        dfs(root, y, pathY);
        if(pathX.size() == pathY.size() && pathX[0] != pathY[0])
            return true;
        return false;
    }
};