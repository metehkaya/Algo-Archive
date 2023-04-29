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
    void dfs(Node* u) {
        if(u == NULL)
            return;
        ans.push_back(u->val);
        int deg = u->children.size();
        for( int i = 0 ; i < deg ; i++ )
            dfs(u->children[i]);
    }
    vector<int> preorder(Node* root) {
        dfs(root);
        return ans;
    }
};