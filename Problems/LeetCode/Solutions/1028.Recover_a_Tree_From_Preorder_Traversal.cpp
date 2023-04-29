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
    TreeNode* recoverFromPreorder(string s) {
        int n = s.length();
        int i = 0 , num = 0;
        while(i < n && s[i] != '-')
            num = 10*num + (s[i++]-'0');
        TreeNode* root = new TreeNode(num);
        vector<TreeNode*> path;
        path.push_back(root);
        while(i < n) {
            int lvl = 0;
            while(i < n && s[i] == '-')
                i++,lvl++;
            path.resize(lvl);
            num = 0;
            while(i < n && s[i] != '-')
                num = 10*num + (s[i++]-'0');
            TreeNode* node = path[lvl-1];
            TreeNode* child = new TreeNode(num);
            path.push_back(child);
            if(node->left == NULL)
                node->left = child;
            else
                node->right = child;
        }
        return root;
    }
};