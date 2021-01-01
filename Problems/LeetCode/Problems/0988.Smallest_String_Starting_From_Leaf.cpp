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
    void dfs(TreeNode* node , string& s , vector<string>& words) {
        if(node->left == NULL && node->right == NULL) {
            string t = s;
            reverse(t.begin(),t.end());
            words.push_back(t);
            return;
        }
        if(node->left != NULL) {
            s.push_back('a'+node->left->val);
            dfs(node->left,s,words);
            s.pop_back();
        }
        if(node->right != NULL) {
            s.push_back('a'+node->right->val);
            dfs(node->right,s,words);
            s.pop_back();
        }
    }
    string smallestFromLeaf(TreeNode* root) {
        string s = "";
        s.push_back('a'+root->val);
        vector<string> words;
        dfs(root,s,words);
        sort(words.begin(),words.end());
        return words[0];
    }
};