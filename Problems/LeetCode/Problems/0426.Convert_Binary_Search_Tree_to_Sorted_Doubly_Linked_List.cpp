class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node() {}
    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }
    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};


class Solution {
public:
    void dfs(Node* node , Node*& prev , Node*& head) {
        if(node == NULL)
            return;
        dfs(node->left,prev,head);
        if(prev == NULL)
            head = prev = node;
        else {
            prev->right = node;
            node->left = prev;
            prev = node;
        }
        dfs(node->right,prev,head);
    }
    Node* treeToDoublyList(Node* root) {
        Node* head = NULL;
        Node* prev = NULL;
        dfs(root,prev,head);
        if(head != NULL) {
            head->left = prev;
            prev->right = head;
        }
        return head;
    }
};