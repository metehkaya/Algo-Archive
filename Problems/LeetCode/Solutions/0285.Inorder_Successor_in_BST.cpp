struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* getLeftMost(TreeNode* node) {
        while(node->left != NULL)
            node = node->left;
        return node;
    }
    TreeNode* getSuccessor(TreeNode* node, int& key, bool& found) {
        TreeNode* res = NULL;
        if(key < node->val) {
            res = getSuccessor(node->left,key,found);
            if(res != NULL)
                return res;
            if(found)
                return node;
        }
        else if(key == node->val) {
            found = true;
            if(node->right == NULL)
                return NULL;
            else
                return getLeftMost(node->right);
        }
        else if(key > node->val)
            return getSuccessor(node->right,key,found);
        return NULL;
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(root == NULL || p == NULL)
            return NULL;
        int key = p->val;
        bool found = false;
        return getSuccessor(root,key,found);
    }
};