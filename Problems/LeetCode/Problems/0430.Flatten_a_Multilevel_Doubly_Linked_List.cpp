class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    void dfs(Node* node , vector<Node*>& v) {
        v.push_back(node);
        if(node->child != NULL)
            dfs(node->child,v);
        if(node->next != NULL)
            dfs(node->next,v);
    }
    Node* flatten(Node* head) {
        if(head == NULL)
            return NULL;
        vector<Node*> v;
        dfs(head,v);
        int n = v.size();
        for( int i = 0 ; i < n ; i++ ) {
            v[i]->child = NULL;
            if(i-1 >= 0)
                v[i]->prev = v[i-1];
            if(i+1 < n)
                v[i]->next = v[i+1];
        }
        return head;
    }
};