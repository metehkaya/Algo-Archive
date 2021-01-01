struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& ar, int l, int r) {
        if(l>r)
            return NULL;
        int mid = (l+r) >> 1;
        TreeNode* node = new TreeNode(ar[mid]);
        node->left = buildTree(ar, l, mid-1);
        node->right = buildTree(ar, mid+1, r);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& ar) {
        int n = ar.size();
        return buildTree(ar,0,n-1);
    }
};