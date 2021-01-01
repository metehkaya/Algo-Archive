struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class FindElements {
public:
    set<int> values;
    FindElements(TreeNode* root) {
        if(root == NULL)
            return;
        dfs(root,0);
    }
    void dfs(TreeNode* node , int val) {
        if(node == NULL)
            return;
        values.insert(val);
        node->val = val;
        dfs(node->left,val*2+1);
        dfs(node->right,val*2+2);
    }
    bool find(int target) {
        return values.find(target) != values.end();
    }
};