struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* x = list1;
        ListNode* y = list1;
        for( int i = 1 ; i < a ; i++ )
            x = x->next;
        for( int i = 0 ; i <= b ; i++ )
            y = y->next;
        x->next = list2;
        ListNode* tail1 = list2;
        ListNode* tail2 = NULL;
        while(tail1 != NULL) {
            tail2 = tail1;
            tail1 = tail1->next;
        }
        tail2->next = y;
        return list1;
    }
};