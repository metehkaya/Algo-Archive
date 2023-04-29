struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* f(ListNode* prv , ListNode* curr , ListNode* nxt , int& cnt , int n) {
        ListNode* node = NULL;
        if(nxt == NULL) {
            cnt = 1;
            if(cnt == n) {
                node = curr;
                if(prv != NULL)
                    prv->next = nxt;
            }
            return node;
        }
        node = f(curr,nxt,nxt->next,cnt,n);
        if(++cnt == n) {
            node = curr;
            if(prv != NULL)
                prv->next = nxt;
        }
        return node;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0;
        ListNode* node = f(NULL,head,head->next,cnt,n);
        ListNode* ans;
        if(node == head)
            ans = node->next;
        else
            ans = head;
        delete node;
        return ans;
    }
};