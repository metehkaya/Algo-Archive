class Node {
public:
    int val;
    vector<Node*> children;
    Node() {}
    Node(int _val) {
        val = _val;
    }
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    void dfsEncode(Node* node , TreeNode* treeNode) {
        vector<TreeNode*> child;
        int deg = node->children.size();
        for( int i = 0 ; i < deg ; i++ )
            child.push_back(new TreeNode(node->children[i]->val));
        if(!child.empty()) {
            treeNode->left = child[0];
            for( int i = 0 ; i < deg ; i++ ) {
                dfsEncode(node->children[i],child[i]);
                if(i+1 < deg)
                    child[i]->right = child[i+1];
            }
        }
    }
    TreeNode* encode(Node* root) {
        if(root == NULL)
            return NULL;
        TreeNode* ans = new TreeNode(root->val);
        dfsEncode(root,ans);
        return ans;
    }
    void dfsDecode(TreeNode* treeNode, Node* node) {
        if(treeNode->left != NULL) {
            TreeNode* currNode = treeNode->left;
            while(currNode != NULL) {
                Node* childNode = new Node(currNode->val);
                node->children.push_back(childNode);
                dfsDecode(currNode,childNode);
                currNode = currNode->right;
            }
        }
    }
    Node* decode(TreeNode* root) {
        if(root == NULL)
            return NULL;
        Node* ans = new Node(root->val);
        dfsDecode(root,ans);
        return ans;
    }
};