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
    vector<int> ans;
    void dfs(Node* node) {
        int deg = node->children.size();
        for( int i = 0 ; i < deg ; i++ )
            dfs(node->children[i]);
        ans.push_back(node->val);
    }
    vector<int> postorder(Node* root) {
        if(root)
            dfs(root);
        return ans;
    }
};