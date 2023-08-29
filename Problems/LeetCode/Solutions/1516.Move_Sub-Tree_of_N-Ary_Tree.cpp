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
    Node* getParent(Node* r, Node* t) {
        Node* parent = NULL;
        for( int i = 0 ; i < r->children.size() && parent == NULL ; i++ )
            parent = r->children[i] == t ? r : getParent(r->children[i], t);
        return parent;
    }
    void removeOrReplace(Node* r, Node* target, Node* replace = NULL) {
        if(r != NULL)
            for( int i = 0 ; i < r->children.size() ; i++ )
                if(r->children[i] == target) {
                    if(replace != NULL)
                        r->children[i] = replace;
                    else
                        r->children.erase(r->children.begin() + i);                
                }
    }
    Node* moveSubTree(Node* root, Node* p, Node* q) {
        auto parentP = getParent(root, p);
        if(parentP != q) {
            auto parentQInP = getParent(p, q);
            if(parentQInP != NULL)
                removeOrReplace(parentQInP, q);
            removeOrReplace(parentP, p, parentQInP != NULL ? q : NULL);
            q->children.push_back(p);
        }
        return root == p ? q : root;
    }
};
