struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    string serialize(TreeNode* root) {
        if(root == NULL)
            return "?";
        return to_string(root->val) + "|" + serialize(root->left) + "|" + serialize(root->right);
    }
    TreeNode* deserialize(string s) {
        int idx = 0;
        int len = s.length();
        return helper(s,idx,len);
    }
    TreeNode* helper(string&s , int& idx , int len) {
        if(s[idx] == '?') {
            idx++;
            return NULL;
        }
        int val = 0;
        while(idx < len && s[idx] != '|')
            val = 10*val + (s[idx++]-'0');
        TreeNode* node = new TreeNode(val);
        idx++;
        node->left = helper(s,idx,len);
        idx++;
        node->right = helper(s,idx,len);
        return node;
    }
};