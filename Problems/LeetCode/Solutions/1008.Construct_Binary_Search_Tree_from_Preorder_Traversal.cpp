struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* makeTree(vector<int>& preorder, int n, int& id, int biggerParent) {
        if(id == n or preorder[id] > biggerParent)
            return NULL;
        TreeNode* node = new TreeNode(preorder[id++]);
        node->left = makeTree(preorder, n, id, node->val);
        node->right = makeTree(preorder, n, id, biggerParent);
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int id = 0;
        int n = preorder.size();
        return makeTree(preorder, n, id, INT_MAX);
    }
};