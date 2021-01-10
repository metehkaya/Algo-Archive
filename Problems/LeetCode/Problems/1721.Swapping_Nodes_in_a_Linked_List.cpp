struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        vector<ListNode*> v;
        for( ListNode* curr = head ; curr != NULL ; curr = curr->next )
            v.push_back(curr);
        int n = v.size();
        int idx1 = k-1;
        int idx2 = n-k;
        int x = v[idx1]->val;
        int y = v[idx2]->val;
        v[idx1]->val = y;
        v[idx2]->val = x;
        return head;
    }
};