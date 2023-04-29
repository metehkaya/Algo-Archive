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
    Node* findRoot(vector<Node*> tree) {
        set<int> vals;
        int n = tree.size();
        for( int i = 0 ; i < n ; i++ ) {
            int deg = tree[i]->children.size();
            for( int j = 0 ; j < deg ; j++ )
                vals.insert(tree[i]->children[j]->val);
        }
        for( int i = 0 ; i < n ; i++ )
            if(vals.find(tree[i]->val) == vals.end())
                return tree[i];
        return NULL;
    }
};