struct PolyNode {
    int coefficient, power;
    PolyNode *next;
    PolyNode(): coefficient(0), power(0), next(nullptr) {};
    PolyNode(int x, int y): coefficient(x), power(y), next(nullptr) {};
    PolyNode(int x, int y, PolyNode* next): coefficient(x), power(y), next(next) {};
};

class Solution {
public:
    void add(PolyNode*& head , PolyNode*& tail , int c , int p) {
        if(head == NULL)
            head = tail = new PolyNode(c,p);
        else {
            tail->next = new PolyNode(c,p);
            tail = tail->next;
        }
    }
    PolyNode* addPoly(PolyNode* p1, PolyNode* p2) {
        PolyNode* head = NULL;
        PolyNode* tail = NULL;
        while(p1 != NULL && p2 != NULL) {
            if(p1->power > p2->power) {
                add(head,tail,p1->coefficient,p1->power);
                p1 = p1->next;
            }
            else if(p2->power > p1->power) {
                add(head,tail,p2->coefficient,p2->power);
                p2 = p2->next;
            }
            else {
                if(p1->coefficient + p2->coefficient)
                    add(head,tail,p1->coefficient+p2->coefficient,p1->power);
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        while(p1 != NULL) {
            add(head,tail,p1->coefficient,p1->power);
            p1 = p1->next;
        }
        while(p2 != NULL) {
            add(head,tail,p2->coefficient,p2->power);
            p2 = p2->next;
        }
        return head;
    }
};