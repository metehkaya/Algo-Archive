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
    int maxh = 0;
    Node* leaf = NULL;
    map<Node*,Node*> mp;
    void dfs2(Node* node , Node* dad , int d) {
        if(d >= maxh)
            maxh = d , leaf = node;
        if(mp[node] != NULL && mp[node] != dad)
            dfs2(mp[node],node,d+1);
        int deg = node->children.size();
        for( int i = 0 ; i < deg ; i++ )
            if(node->children[i] != dad)
                dfs2(node->children[i],node,d+1);
    }
    void dfs1(Node* node , Node* dad , int d) {
        if(d >= maxh)
            maxh = d , leaf = node;
        mp[node] = dad;
        int deg = node->children.size();
        for( int i = 0 ; i < deg ; i++ )
            dfs1(node->children[i],node,d+1);
    }
    int diameter(Node* root) {
        if(root == NULL)
            return 0;
        dfs1(root,NULL,0);
        root = leaf;
        maxh = 0;
        leaf = NULL;
        dfs2(root,NULL,0);
        return maxh;
    }
};