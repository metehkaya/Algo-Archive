struct Node {
    int val;
    Node *left;
    Node *right;
    Node *random;
    Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
    Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
};

class Solution {
public:
    map<Node*,NodeCopy*> mp;
    void dfs(Node* node , NodeCopy* copyNode) {
        mp[node] = copyNode;
        if(node->left) {
            copyNode->left = new NodeCopy(node->left->val);
            dfs(node->left,copyNode->left);
        }
        if(node->right) {
            copyNode->right = new NodeCopy(node->right->val);
            dfs(node->right,copyNode->right);
        }
    }
    NodeCopy* copyRandomBinaryTree(Node* root) {
        if(root == NULL)
            return NULL;
        NodeCopy* copyRoot = new NodeCopy(root->val);
        dfs(root,copyRoot);
        for(auto it : mp) {
            Node* node = it.first;
            NodeCopy* copyNode = it.second;
            copyNode->random = mp[node->random];
        }
        return copyRoot;
    }
};