struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void dfs(TreeNode* node , TreeNode* dest , vector<TreeNode*>& res , vector<TreeNode*>& curr) {
        curr.push_back(node);
        if(node == dest)
            res = curr;
        if(node->left)
            dfs(node->left,dest,res,curr);
        if(node->right)
            dfs(node->right,dest,res,curr);
        curr.pop_back();
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return NULL;
        vector<TreeNode*> v1,v2;
        vector<TreeNode*> v;
        dfs(root,p,v1,v);
        dfs(root,q,v2,v);
        if(v1.empty() or v2.empty())
            return NULL;
        int n = min(v1.size(),v2.size());
        int last = 0;
        while(last < n) {
            if(v1[last] != v2[last])
                break;
            last++;
        }
        return v1[--last];
    }
};