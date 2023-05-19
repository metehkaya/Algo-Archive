struct RopeTreeNode {
    int len;
    string val;
    RopeTreeNode *left;
    RopeTreeNode *right;
    RopeTreeNode() : len(0), val(""), left(nullptr), right(nullptr) {}
    RopeTreeNode(string s) : len(0), val(std::move(s)), left(nullptr), right(nullptr) {}
    RopeTreeNode(int x) : len(x), val(""), left(nullptr), right(nullptr) {}
    RopeTreeNode(int x, RopeTreeNode *left, RopeTreeNode *right) : len(x), val(""), left(left), right(right) {}
};

class Solution {
public:
    string s = "";
    void dfs(RopeTreeNode* node) {
        if(node == NULL)
            return;
        if(node->len == 0) {
            s += node->val;
            return;
        }
        dfs(node->left);
        dfs(node->right);
    }
    char getKthCharacter(RopeTreeNode* root, int k) {
        dfs(root);
        return s[k-1];
    }
};
