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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode* node = new TreeNode(val);
        if(root == NULL or val > root->val) {
            node->left = root;
            root = node;
        }
        else {
            TreeNode* curr = root;
            while(curr->right and val < curr->right->val)
                curr = curr->right;
            if(curr->right == NULL)
                curr->right = node;
            else {
                TreeNode* temp = curr->right;
                curr->right = node;
                node->left = temp;
            }
        }
        return root;
    }
};