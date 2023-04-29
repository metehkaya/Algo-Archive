struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int t) {
        while(head && head->val == t)
            head = head->next;
        if(head == NULL)
            return head;
        ListNode* node = head;
        while(node && node->next) {
            while(node->next != NULL && node->next->val == t)
                node->next = node->next->next;
            node = node->next;
        }
        return head;
    }
};