struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* myHead = NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr != NULL && curr->next != NULL) {
            ListNode* nxt = curr->next;
            if(myHead == NULL)
                myHead = nxt;
            if(prev != NULL)
                prev->next = nxt;
            prev = curr;
            curr->next = nxt->next;
            nxt->next = curr;
            curr = curr->next;
        }
        return myHead;
    }
};