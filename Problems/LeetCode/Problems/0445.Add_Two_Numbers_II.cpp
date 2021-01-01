struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* revLL(ListNode* node) {
        ListNode* head;
        ListNode* prev = NULL;
        while(node != NULL) {
            head = node;
            ListNode* temp = node->next;
            node->next = prev;
            prev = node;
            node = temp;
        }
        return head;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = revLL(l1);
        l2 = revLL(l2);
        int add = 0;
        ListNode* head = NULL;
        while(l1 != NULL || l2 != NULL) {
            int sum = add;
            if(l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }
            add = sum/10;
            sum %= 10;
            if(head == NULL) {
                head = new ListNode(sum);
            }
            else {
                ListNode* node = new ListNode(sum);
                node->next = head;
                head = node;
            }
        }
        if(add) {
            ListNode* node = new ListNode(1);
            node->next = head;
            head = node;
        }
        return head;
    }
};