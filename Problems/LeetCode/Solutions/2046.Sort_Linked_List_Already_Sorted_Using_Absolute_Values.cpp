class Solution {
public:
    ListNode* sortLinkedList(ListNode* head) {
        ListNode *pos_head = NULL , *pos_tail = NULL , *neg_head = NULL , *neg_tail = NULL;
        ListNode* node = head;
        while(node != NULL) {
            ListNode* node_next = node->next;
            if(node->val >= 0) {
                if(pos_head == NULL)
                    pos_head = pos_tail = node;
                else {
                    pos_tail->next = node;
                    pos_tail = node;
                }
            }
            else {
                if(neg_head == NULL)
                    neg_head = neg_tail = node;
                else {
                    node->next = neg_head;
                    neg_head = node;
                }
            }
            node = node_next;
        }
        if(pos_tail)
            pos_tail->next = NULL;
        if(neg_tail)
            neg_tail->next = pos_head ? pos_head : NULL;
        return neg_head ? neg_head : pos_head;
    }
};
