struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

typedef pair<TreeNode*,TreeNode*> ptt;

class CBTInserter {
public:
    TreeNode* root;
    queue<TreeNode*> Q;
    CBTInserter(TreeNode* node) {
        queue<ptt> bfsQ;
        root = new TreeNode(node->val);
        bfsQ.push(ptt(root,node));
        while(!bfsQ.empty()) {
            ptt temp = bfsQ.front();
            bfsQ.pop();
            TreeNode* myNode = temp.first;
            node = temp.second;
            if(node->left == NULL or node->right == NULL)
                Q.push(myNode);
            if(node->left != NULL) {
                myNode->left = new TreeNode(node->left->val);
                bfsQ.push(ptt(myNode->left,node->left));
            }
            if(node->right != NULL) {
                myNode->right = new TreeNode(node->right->val);
                bfsQ.push(ptt(myNode->right,node->right));
            }
        }
    }
    int insert(int v) {
        TreeNode* node = Q.front();
        TreeNode* child = new TreeNode(v);
        if(node->left == NULL)
            node->left = child;
        else
            node->right = child , Q.pop();
        Q.push(child);
        return node->val;
    }
    TreeNode* get_root() {
        return root;
    }
};