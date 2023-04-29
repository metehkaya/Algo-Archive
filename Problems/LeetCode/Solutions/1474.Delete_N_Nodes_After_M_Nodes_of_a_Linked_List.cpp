struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteNodes(ListNode* head, int n, int m) {
        ListNode *curr = head , *prev = NULL;
        int rem = n;
        bool add = true;
        while(curr != NULL) {
            if(add) {
                if(prev != NULL)
                    prev->next = curr;
                prev = curr;
            }
            ListNode* nxt = curr->next;
            curr->next = NULL;
            if(!add)
                delete curr;
            curr = nxt;
            if(--rem == 0) {
                if(add) {
                    rem = m;
                    add = false;
                }
                else {
                    rem = n;
                    add = true;
                }
            }
        }
        return head;
    }
};