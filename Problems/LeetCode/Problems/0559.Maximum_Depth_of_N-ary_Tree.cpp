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
    int dfs(Node* node) {
        int res = 1;
        int deg = node->children.size();
        for( int i = 0 ; i < deg ; i++ )
            res = max( res , dfs(node->children[i]) + 1 );
        return res;
    }
    int maxDepth(Node* root) {
        if(root == NULL)
            return 0;
        return dfs(root);
    }
};