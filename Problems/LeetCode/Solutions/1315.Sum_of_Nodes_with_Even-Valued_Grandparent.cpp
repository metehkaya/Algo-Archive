struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int dfs(TreeNode* root, int parent, int grand) {
        if(root == NULL)
            return 0;
        int sum = 0;
        if(grand % 2 == 0)
            sum += root->val;
        sum += dfs(root->left, root->val, parent);
        sum += dfs(root->right, root->val, parent);
        return sum;
    }
    int sumEvenGrandparent(TreeNode* root) {
        return dfs(root,-1,-1);
    }
};