class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    void dfs(Node* node, int lvl, vector<Node*>& nodes) {
        if(node == NULL)
            return;
        if(lvl > (int) nodes.size())
            nodes.resize(lvl);
        if(node->left != NULL) {
            dfs(node->right, lvl+1, nodes);
            dfs(node->left, lvl+1, nodes);
        }
        node->next = nodes[lvl-1];
        nodes[lvl-1] = node;
    }
    Node* connect(Node* root) {
        vector<Node*> nodes;
        dfs(root, 1, nodes);
        return root;
    }
};