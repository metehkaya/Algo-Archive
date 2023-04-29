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
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        Node* res = NULL;
        if(quadTree1->isLeaf && quadTree2->isLeaf)
            res = new Node(quadTree1->val | quadTree2->val , true);
        else if(!quadTree1->isLeaf && !quadTree2->isLeaf) {
            Node* topLeft = intersect(quadTree1->topLeft,quadTree2->topLeft);
            Node* topRight = intersect(quadTree1->topRight,quadTree2->topRight);
            Node* bottomLeft = intersect(quadTree1->bottomLeft,quadTree2->bottomLeft);
            Node* bottomRight = intersect(quadTree1->bottomRight,quadTree2->bottomRight);
            if(topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf) {
                bool vals[2] = {false,false};
                vals[topLeft->val] = vals[topRight->val] = vals[bottomLeft->val] = vals[bottomRight->val] = true;
                if(vals[0] && vals[1])
                    res = new Node(false,false,topLeft,topRight,bottomLeft,bottomRight);
                else
                    res = new Node(vals[1],true);
            }
            else
                res = new Node(false,false,topLeft,topRight,bottomLeft,bottomRight);
        }
        else {
            if(quadTree1->isLeaf)
                swap(quadTree1,quadTree2);
            if(quadTree2->val == 1)
                res = quadTree2;
            else
                res = quadTree1;
        }
        return res;
    }
};
