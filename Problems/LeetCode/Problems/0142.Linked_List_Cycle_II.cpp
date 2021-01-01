struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL)
            return NULL;
        if(head->next == NULL)
            return NULL;
        ListNode* slowNode = head->next;
        ListNode* fastNode = head->next->next;
        while(slowNode != NULL && fastNode != NULL && slowNode != fastNode) {
            slowNode = slowNode->next;
            fastNode = fastNode->next;
            if(fastNode != NULL)
                fastNode = fastNode->next;
        }
        if(slowNode == NULL || fastNode == NULL)
            return NULL;
        slowNode = head;
        while(slowNode != fastNode) {
            slowNode = slowNode->next;
            fastNode = fastNode->next;
        }
        return slowNode;
    }
};