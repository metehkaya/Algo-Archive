struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL)
            return false;
        if(head->next == NULL)
            return false;
        ListNode* slowNode = head->next;
        ListNode* fastNode = head->next->next;
        while(slowNode != NULL && fastNode != NULL && slowNode != fastNode) {
            slowNode = slowNode->next;
            fastNode = fastNode->next;
            if(fastNode != NULL)
                fastNode = fastNode->next;
        }
        if(slowNode == NULL || fastNode == NULL)
            return false;
        return true;
    }
};