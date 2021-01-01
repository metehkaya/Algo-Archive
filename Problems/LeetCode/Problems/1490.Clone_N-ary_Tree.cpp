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

class Solution {
public:
    void dfs(Node* node , Node* cloneNode) {
        int deg = node->children.size();
        for( int i = 0 ; i < deg ; i++ ) {
            Node* child = node->children[i];
            Node* cloneChild = new Node(child->val);
            cloneNode->children.push_back(cloneChild);
            dfs(child,cloneChild);
        }
    }
    Node* cloneTree(Node* root) {
        if(root == NULL)
            return NULL;
        Node* cloneRoot = new Node(root->val);
        dfs(root,cloneRoot);
        return cloneRoot;
    }
};