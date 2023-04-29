struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL)
            return NULL;
        if(head->next == NULL)
            return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* lastOdd = odd;
        ListNode* firstEven = even;
        while(odd != NULL && even != NULL) {
            ListNode* oddNext = even->next;
            ListNode* evenNext = NULL;
            if(oddNext != NULL)
                evenNext = oddNext->next;
            odd->next = oddNext;
            even->next = evenNext;
            odd = oddNext;
            even = evenNext;
            if(odd != NULL)
                lastOdd = odd;
        }
        lastOdd->next = firstEven;
        return head;
    }
};