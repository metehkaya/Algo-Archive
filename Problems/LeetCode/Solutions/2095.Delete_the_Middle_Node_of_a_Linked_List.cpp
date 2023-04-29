struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        int n = 0;
        ListNode* node = head;
        while(node) {
            n++;
            node = node->next;
        }
        node = head;
        ListNode* prev = NULL;
        for( int i = 0 ; i < n/2 ; i++ ) {
            prev = node;
            node = node->next;
        }
        if(prev == NULL)
            head = head->next;
        else
            prev->next = node->next;
        return head;
    }
};
