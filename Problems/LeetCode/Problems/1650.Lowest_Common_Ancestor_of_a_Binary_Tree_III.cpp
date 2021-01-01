class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        set<Node*> v;
        while(p != NULL) {
            v.insert(p);
            p = p->parent;
        }
        while(q != NULL) {
            if(v.find(q) != v.end())
                return q;
            q = q->parent;
        }
        return NULL;
    }
};