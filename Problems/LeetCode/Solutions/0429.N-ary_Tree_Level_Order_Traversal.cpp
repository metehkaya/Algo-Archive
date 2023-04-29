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
    vector<int> empty;
    vector<vector<int>> ans;
    void dfs(Node* node , int lvl) {
        if(lvl == ans.size())
            ans.push_back(empty);
        ans[lvl].push_back(node->val);
        int deg = node->children.size();
        for( int i = 0 ; i < deg ; i++ )
            dfs(node->children[i],lvl+1);
    }
    vector<vector<int>> levelOrder(Node* root) {
        if(root != NULL)
            dfs(root,0);
        return ans;
    }
};