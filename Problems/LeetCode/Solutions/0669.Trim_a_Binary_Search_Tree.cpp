struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* getNodeInInterval(TreeNode* node, int& L, int& R) {
        if(node == NULL)
            return NULL;
        if(node->val >= L && node->val <= R)
            return node;
        else if(node->val > R)
            return getNodeInInterval(node->left, L, R);
        else
            return getNodeInInterval(node->right, L, R);
    }
    void deleteNodes(TreeNode* node, TreeNode* parent, int& L, int& R) {
        if(node == NULL)
            return;
        if(node->val < L) {
            TreeNode* tmp = node;
            while(tmp != NULL && tmp->val < L)
                tmp = tmp->right;
            parent->left = tmp;
            deleteNodes(tmp, parent, L, R);
        }
        else if(node->val > R) {
            TreeNode* tmp = node;
            while(tmp != NULL && tmp->val > R)
                tmp = tmp->left;
            parent->right = tmp;
            deleteNodes(tmp, parent, L, R);
        }
        else {
            deleteNodes(node->left,node,L,R);
            deleteNodes(node->right,node,L,R);
        }
    }
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(root == NULL)
            return NULL;
        TreeNode* validRoot = getNodeInInterval(root,L,R);
        if(validRoot == NULL)
            return NULL;
        deleteNodes(validRoot,NULL,L,R);
        return validRoot;
    }
};