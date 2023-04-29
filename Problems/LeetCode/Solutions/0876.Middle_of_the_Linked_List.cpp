struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head == NULL)
            return NULL;
        int n = 0;
        for( ListNode* node = head ; node != NULL ; node = node->next )
            n++;
        ListNode* mid = head;
        for( int i = 0 ; i < n/2 ; i++ )
            mid = mid->next;
        return mid;
    }
};