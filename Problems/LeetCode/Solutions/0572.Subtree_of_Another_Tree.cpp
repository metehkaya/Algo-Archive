struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void findRoots(TreeNode* root, TreeNode* t, vector<TreeNode*>& roots) {
        if(root == NULL)
            return;
        if(root->val == t->val)
            roots.push_back(root);
        findRoots(root->left,t,roots);
        findRoots(root->right,t,roots);
    }
    bool isSame(TreeNode* s, TreeNode* t) {
        if(s == NULL && t != NULL)
            return false;
        if(s != NULL && t == NULL)
            return false;
        if(s == NULL && t == NULL)
            return true;
        bool val = (s->val == t->val) && isSame(s->left,t->left) && isSame(s->right,t->right);
        return val;
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s == NULL || t == NULL)
            return false;
        vector<TreeNode*> roots;
        findRoots(s,t,roots);
        bool ans = false;
        for( int i = 0 ; i < roots.size() && !ans ; i++ )
            ans = isSame(roots[i],t);
        return ans;
    }
};