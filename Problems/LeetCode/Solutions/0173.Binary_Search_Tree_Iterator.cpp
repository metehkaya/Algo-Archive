struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
public:
    int n;
    int idx = 0;
    vector<int> nums;
    void dfs(TreeNode* node) {
        if(node == NULL)
            return;
        if(node->left)
            dfs(node->left);
        nums.push_back(node->val);
        if(node->right)
            dfs(node->right);
    }
    BSTIterator(TreeNode* root) {
        dfs(root);
        n = nums.size();
    }
    int next() {
        return nums[idx++];
    }
    bool hasNext() {
        return idx < n;
    }
};