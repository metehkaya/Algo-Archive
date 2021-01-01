struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void split(TreeNode* node, vector<TreeNode*>& ans) {
        if(node->left != NULL)
            ans.push_back(node->left);
        if(node->right != NULL)
            ans.push_back(node->right);
    }
    void dfs(TreeNode* node, unordered_set<int>& ids, vector<TreeNode*>& ans) {
        if(node->left != NULL) {
            dfs(node->left, ids, ans);
            if(ids.find(node->left->val) != ids.end()) {
                split(node->left, ans);
                node->left = NULL;
            }
        }
        if(node->right != NULL) {
            dfs(node->right, ids, ans);
            if(ids.find(node->right->val) != ids.end()) {
                split(node->right, ans);
                node->right = NULL;
            }
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        if(root == NULL)
            return ans;
        unordered_set<int> ids;
        for( int i = 0 ; i < to_delete.size() ; i++ )
            ids.insert(to_delete[i]);
        dfs(root, ids, ans);
        if(ids.find(root->val) != ids.end()) {
            if(root->left != NULL)
                ans.push_back(root->left);
            if(root->right != NULL)
                ans.push_back(root->right);
        }
        else
            ans.push_back(root);
        return ans;
    }
};