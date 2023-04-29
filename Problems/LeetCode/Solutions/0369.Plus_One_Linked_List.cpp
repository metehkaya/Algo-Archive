struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool goo(ListNode* node) {
        if(node == NULL)
            return true;
        bool all9s = goo(node->next);
        if(all9s) {
            if(node->val == 9) {
                node->val = 0;
                return true;
            }
            node->val++;
            return false;
        }
        return false;
    }
    ListNode* plusOne(ListNode* head) {
        bool all9s = goo(head);
        if(all9s) {
            ListNode* newHead = new ListNode(1);
            newHead->next = head;
            head = newHead;
        }
        return head;
    }
};