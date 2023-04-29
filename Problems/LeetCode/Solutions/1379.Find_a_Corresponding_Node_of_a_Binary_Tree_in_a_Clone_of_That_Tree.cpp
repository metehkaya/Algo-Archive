struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<bool> goLeft;
    bool dfs(TreeNode* node , TreeNode* target) {
        if(node == target)
            return true;
        if(node->left) {
            goLeft.push_back(true);
            if(dfs(node->left,target))
                return true;
            goLeft.pop_back();
        }
        if(node->right) {
            goLeft.push_back(false);
            if(dfs(node->right,target))
                return true;
            goLeft.pop_back();
        }
        return false;
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        dfs(original,target);
        int p = goLeft.size();
        TreeNode* ans = cloned;
        for( int i = 0 ; i < p ; i++ )
            if(goLeft[i])
                ans = ans->left;
            else
                ans = ans->right;
        return ans;
    }
};