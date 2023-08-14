struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* node = head;
        while(node->next) {
            ListNode* nxt = node->next;
            int g = __gcd(node->val,nxt->val);
            ListNode* mid = new ListNode(g);
            node->next = mid;
            mid->next = nxt;
            node = nxt;
        }
        return head;
    }
};
