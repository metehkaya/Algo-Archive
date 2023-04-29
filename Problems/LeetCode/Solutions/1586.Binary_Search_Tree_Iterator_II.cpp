class BSTIterator {
public:
    int id;
    vector<int> vals;
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        id = -1;
        goLeft(root);
    }
    void goLeft(TreeNode* node) {
        while(node) {
            st.push(node);
            node = node->left;
        }
    }
    bool hasNext() {
        return !st.empty() or id+1 < vals.size();
    }
    int next() {
        if(id+1 == vals.size()) {
            TreeNode* node = st.top();
            st.pop();
            vals.push_back(node->val);
            goLeft(node->right);
        }
        return vals[++id];
    }
    bool hasPrev() {
        return id > 0;
    }
    int prev() {
        return vals[--id];
    }
};
