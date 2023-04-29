struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* node = head;
        while(node != NULL) {
            ListNode* temp = head;
            while(temp != node) {
                if(temp->val > node->val)
                    break;
                temp = temp->next;
            }
            int val = node->val;
            if(node != temp) {
                ListNode* temp2 = temp;
                int bef = temp2->val;
                temp2 = temp2->next;
                while(temp2 != node) {
                    int bef2 = temp2->val;
                    temp2->val = bef;
                    bef = bef2;
                    temp2 = temp2->next;
                }
                temp->val = val;
                temp2->val = bef;
            }
            node = node->next;
        }
        return head;
    }
};