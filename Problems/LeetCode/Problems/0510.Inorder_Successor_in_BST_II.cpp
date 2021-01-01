class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};

class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        Node* ans = NULL;
        if(node->right) {
            node = node->right;
            while(node->left)
                node = node->left;
            ans = node;
        }
        else {
            Node* par = node->parent;
            Node* child = node;
            while(par && par->left != child) {
                child = par;
                par = par->parent;
            }
            ans = par;
        }
        return ans;
    }
};