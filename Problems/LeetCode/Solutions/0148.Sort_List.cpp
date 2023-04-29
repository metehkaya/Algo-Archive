struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> v;
        for( ListNode* node = head ; node != NULL ; node = node->next )
            v.push_back(node->val);
        sort(v.begin(),v.end());
        int curr = 0;
        for( ListNode* node = head ; node != NULL ; node = node->next , curr++ )
            node->val = v[curr];
        return head;
    }
};