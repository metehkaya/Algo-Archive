class Node {
public:
    int val;
    vector<Node*> neighbors;    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    const int MAXV = 101;
    void dfs(Node* u , vector<Node*>& nodes) {
        Node* cloneU = nodes[u->val];
        int deg = u->neighbors.size();
        for( int i = 0 ; i < deg ; i++ ) {
            Node* v = u->neighbors[i];
            if(nodes[v->val] == NULL) {
                nodes[v->val] = new Node(v->val);
                dfs(v,nodes);
            }
            cloneU->neighbors.push_back(nodes[v->val]);
        }
    }
    Node* cloneGraph(Node* node) {
        if(node == NULL)
            return NULL;
        vector<Node*> nodes(MAXV,NULL);
        nodes[node->val] = new Node(node->val);
        dfs(node,nodes);
        return nodes[node->val];
    }
};