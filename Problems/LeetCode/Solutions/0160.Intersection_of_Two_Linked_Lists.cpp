struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL)
            return NULL;
        int nA=0,nB=0;
        ListNode* nodeA=headA;
        ListNode* nodeB=headB;
        while(nodeA) {
            nA++;
            nodeA = nodeA->next;
        }
        while(nodeB) {
            nB++;
            nodeB = nodeB->next;
        }
        while(nA>nB) {
            nA--;
            headA = headA->next;
        }
        while(nB>nA) {
            nB--;
            headB = headB->next;
        }
        while(headA != NULL && headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};