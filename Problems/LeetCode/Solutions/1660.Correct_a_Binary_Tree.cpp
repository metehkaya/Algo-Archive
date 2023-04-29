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
    set<TreeNode*> s;
    bool dfs(TreeNode* node , TreeNode* par , bool isLeft) {
        s.insert(node);
        if(node->right) {
            if(s.find(node->right) != s.end()) {
                if(isLeft)
                    par->left = NULL;
                else
                    par->right = NULL;
                return true;
            }
            if(dfs(node->right,node,false))
                return true;
        }
        if(node->left)
            if(dfs(node->left,node,true))
                return true;
        return false;
    }
    TreeNode* correctBinaryTree(TreeNode* root) {
        dfs(root,NULL,false);
        return root;
    }
};