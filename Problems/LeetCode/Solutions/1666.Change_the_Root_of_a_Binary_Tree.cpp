class Solution {
public:
    Node* flipBinaryTree(Node* root, Node * leaf) {
        return rebuild(leaf,NULL,root);
    }
    Node* rebuild(Node* node, Node* new_dad, Node* old_root) {
        Node* old_dad = node->parent;
        node->parent = new_dad;
        if(node->left == new_dad)
            node->left = NULL;
        if(node->right == new_dad)
            node->right = NULL;
        if(node == old_root)
            return node;
        if(node->left)
            node->right = node->left;
        node->left = rebuild(old_dad,node,old_root);
        return node;
    }
};
