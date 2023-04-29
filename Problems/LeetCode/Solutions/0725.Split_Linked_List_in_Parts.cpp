struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int n,k;
    vector<ListNode*> ans;
    void f(ListNode* head, int id) {
        if(id == k)
            return;
        ans.push_back(head);
        if(head == NULL)
            f(NULL,id+1);
        else {
            int cnt = n/k + (id < (n%k));
            ListNode* tail = head;
            while(--cnt)
                tail = tail->next;
            ListNode* next = tail->next;
            tail->next = NULL;
            f(next,id+1);
        }
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        this->k = k;
        ListNode* tail = head;
        while(tail != NULL) {
            n++;
            tail = tail->next;
        }
        f(head,0);
        return ans;
    }
};