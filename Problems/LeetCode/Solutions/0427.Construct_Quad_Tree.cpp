class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
public:
    int n;
    vector<vector<int>> ar;
    void g(Node* node , int& cntLeaf , vector<bool>& vals) {
        cntLeaf += node->isLeaf;
        vals[node->val] = true;
    }
    void f(Node* node , int x1 , int x2 , int y1 , int y2) {
        if(x1 == x2 && y1 == y2) {
            node->isLeaf = true;
            node->val = ar[x1][y1];
            return;
        }
        int xmid = (x1+x2) >> 1;
        int ymid = (y1+y2) >> 1;
        int cntLeaf = 0;
        vector<bool> vals(2,false);
        node->topLeft = new Node();
        f(node->topLeft,x1,xmid,y1,ymid);
        g(node->topLeft,cntLeaf,vals);
        node->topRight = new Node();
        f(node->topRight,x1,xmid,ymid+1,y2);
        g(node->topRight,cntLeaf,vals);
        node->bottomLeft = new Node();
        f(node->bottomLeft,xmid+1,x2,y1,ymid);
        g(node->bottomLeft,cntLeaf,vals);
        node->bottomRight = new Node();
        f(node->bottomRight,xmid+1,x2,ymid+1,y2);
        g(node->bottomRight,cntLeaf,vals);
        if(cntLeaf == 4 && (vals[0] ^ vals[1])) {
            int valnew = vals[1];
            node->isLeaf = true;
            node->val = valnew;
            delete node->topLeft;
            node->topLeft = NULL;
            delete node->topRight;
            node->topRight = NULL;
            delete node->bottomLeft;
            node->bottomLeft = NULL;
            delete node->bottomRight;
            node->bottomRight = NULL;
        }
    }
    Node* construct(vector<vector<int>>& ar) {
        n = ar.size();
        this->ar = ar;
        Node* root = new Node();
        f(root,0,n-1,0,n-1);
        return root;
    }
};