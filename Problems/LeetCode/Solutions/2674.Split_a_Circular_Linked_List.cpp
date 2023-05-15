class Solution {
public:
    vector<ListNode*> splitCircularLinkedList(ListNode* head1) {
        int n = 1;
        ListNode* tail2 = head1;
        while(tail2->next != head1) {
            n += 1;
            tail2 = tail2->next;
        }
        ListNode* tail1 = head1;
        int cnt = (n+1)/2 - 1;
        while(cnt--)
            tail1 = tail1->next;
        ListNode* head2 = tail1->next;
        tail1->next = head1;
        tail2->next = head2;
        vector<ListNode*> heads({head1,head2});
        return heads;
    }
};
