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
    TreeNode* root = NULL;
    unordered_set<int> mark;
    unordered_map<TreeNode*,TreeNode*> mp;
    bool dfs(TreeNode* node , TreeNode* dad , int k) {
        if(dad != NULL)
            mp[node] = dad;
        if(node->val == k) {
            root = node;
            return true;
        }
        if(node->left)
            if(dfs(node->left,node,k))
                return true;
        if(node->right)
            if(dfs(node->right,node,k))
                return true;
        return false;
    }
    int findClosestLeaf(TreeNode* node, int k) {
        dfs(node,NULL,k);
        queue<TreeNode*> q;
        q.push(root);
        mark.insert(root->val);
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if(node->left == NULL && node->right == NULL)
                return node->val;
            if(node->left != NULL && mark.find(node->left->val) == mark.end()) {
                q.push(node->left);
                mark.insert(node->left->val);
            }
            if(node->right != NULL && mark.find(node->right->val) == mark.end()) {
                q.push(node->right);
                mark.insert(node->right->val);
            }
            if(mp.find(node) != mp.end() && mark.find(mp[node]->val) == mark.end()) {
                q.push(mp[node]);
                mark.insert(mp[node]->val);
            }
        }
        return -1;
    }
};