struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* revList(ListNode* curr , ListNode* prev) {
        ListNode* temp = curr->next;
        curr->next = prev;
        if(temp == NULL)
            return curr;
        return revList(temp,curr);
    }
    ListNode* reverseList(ListNode* head) {
        if(head == NULL or head->next == NULL)
            return head;
        return revList(head,NULL);
    }
};