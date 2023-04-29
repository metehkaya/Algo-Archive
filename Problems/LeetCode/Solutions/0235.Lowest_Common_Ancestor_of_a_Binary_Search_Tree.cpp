struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val == p->val || root->val == q->val)
            return root;
        int wayP,wayQ;
        if(p->val < root->val)
            wayP = 1;
        else
            wayP = 2;
        if(q->val < root->val)
            wayQ = 1;
        else
            wayQ = 2;
        if(wayP != wayQ)
            return root;
        if(wayP == 1)
            return lowestCommonAncestor(root->left, p, q);
        return lowestCommonAncestor(root->right, p, q);
    }
};