struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        int sum = 0;
        ListNode *ans = NULL , *tail = NULL;
        while(head != NULL) {
            int val = head->val;
            head = head->next;
            if(val == 0) {
                if(sum) {
                    if(ans == NULL)
                        ans = tail = new ListNode(sum);
                    else {
                        tail->next = new ListNode(sum);
                        tail = tail->next;
                    }
                }
                sum = 0;
            }
            else
                sum += val;
        }
        return ans;
    }
};
