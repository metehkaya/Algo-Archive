struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        ListNode* tail = NULL;
        int add=0;
        while(l1 != NULL && l2 != NULL) {
            int sum = add + l1->val + l2->val;
            add = sum/10;
            if(head == NULL)
                head = tail = new ListNode(sum%10);
            else {
                tail->next = new ListNode(sum%10);
                tail = tail->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != NULL) {
            int sum = add + l1->val;
            add = sum/10;
            tail->next = new ListNode(sum%10);
            tail = tail->next;
            l1 = l1->next;
        }
        while(l2 != NULL) {
            int sum = add + l2->val;
            add = sum/10;
            tail->next = new ListNode(sum%10);
            tail = tail->next;
            l2 = l2->next;
        }
        if(add) {
            tail->next = new ListNode(add);
            tail = tail->next;
        }
        return head;
    }
};