struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* findNode(TreeNode* node, double& target, double& diff) {
        if(node == NULL)
            return NULL;
        TreeNode* result = NULL;
        double temp = fabs(node->val - target);
        if(temp < diff) {
            diff = temp;
            result = node;
        }
        if(node->val == target) {
        }
        else if(node->val < target) {
            TreeNode* stNode = findNode(node->right, target, diff);
            if(stNode != NULL && stNode != result)
                result = stNode;
        }
        else if(node->val > target) {
            TreeNode* stNode = findNode(node->left, target, diff);
            if(stNode != NULL && stNode != result)
                result = stNode;
        }
        return result;
    }
    int closestValue(TreeNode* root, double target) {
        double diff = fabs(root->val - target);
        TreeNode* node = findNode(root, target, diff);
        if(node != NULL)
            return node->val;
        else
            return root->val;
    }
};