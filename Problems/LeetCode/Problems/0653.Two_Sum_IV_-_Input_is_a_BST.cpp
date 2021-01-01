struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool dfs(TreeNode* root, int k, unordered_set<int>& myset) {
        if(root == NULL)
            return false;
        if( dfs(root->left,k,myset) )
            return true;
        int key = k - root->val;
        if(myset.find(key) != myset.end())
            return true;
        myset.insert(root->val);
        if( dfs(root->right,k,myset) )
            return true;
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> myset;
        return dfs(root,k,myset);
    }
};