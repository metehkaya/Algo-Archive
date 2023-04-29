struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void solve(ListNode* node , int& sum) {
        if(node == NULL)
            return;
        sum = 2*sum + node->val;
        solve(node->next,sum);
    }
    int getDecimalValue(ListNode* head) {
        int sum = 0;
        solve(head,sum);
        return sum;
    }
};