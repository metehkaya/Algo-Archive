struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)
            return NULL;
        int n = 0;
        ListNode* tail = NULL;
        for( ListNode* node = head ; node != NULL ; node = node->next ) {
            n++;
            tail = node;
        }
        k = (n - (k%n)) % n;
        if(k == 0)
            return head;
        ListNode* ans = head;
        ListNode* bef = NULL;
        for( int i = 0 ; i < k ; i++ ) {
            bef = ans;
            ans = ans->next;
        }
        bef->next = NULL;
        tail->next = head;
        return ans;
    }
};