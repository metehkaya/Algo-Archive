/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> sum;
    unordered_map<TreeNode*,int> mp;
    void dfs2(TreeNode* node , int lvl) {
        if(lvl == 0)
            node->val = 0;
        if(node->left) {
            node->left->val = sum[lvl+1]-mp[node];
            dfs2(node->left,lvl+1);
        }
        if(node->right) {
            node->right->val = sum[lvl+1]-mp[node];
            dfs2(node->right,lvl+1);
        }
    }
    void dfs(TreeNode* node , int lvl) {
        if(lvl == sum.size())
            sum.push_back(node->val);
        else
            sum[lvl] += node->val;
        mp[node] = 0;
        if(node->left) {
            mp[node] += node->left->val;
            dfs(node->left,lvl+1);
        }
        if(node->right) {
            mp[node] += node->right->val;
            dfs(node->right,lvl+1);
        }
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        dfs(root,0);
        dfs2(root,0);
        return root;
    }
};
