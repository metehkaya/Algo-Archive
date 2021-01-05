struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ans = NULL;
        ListNode* tail = NULL;
        ListNode* l = head;
        while(l != NULL) {
            int cnt = 0;
            ListNode* r = l;
            while(r != NULL && l->val == r->val)
                cnt++ , r = r->next;
            if(ans == NULL)
                ans = tail = l;
            else {
                tail->next = l;
                tail = l;
            }
            l = l->next;
            while(l != r) {
                ListNode* nextNode = l->next;
                l->next = NULL;
                delete l;
                l = nextNode;
            }
        }
        if(tail != NULL)
            tail->next = NULL;
        return ans;
    }
};