struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL)
            return NULL;
        vector<ListNode*> left,right;
        for( ListNode* node = head ; node != NULL ; node = node->next ) {
            if(node->val < x)
                left.push_back(node);
            else
                right.push_back(node);
        }
        int l = left.size();
        int r = right.size();
        for( int i = 0 ; i < l-1 ; i++ )
            left[i]->next = left[i+1];
        for( int i = 0 ; i < r-1 ; i++ )
            right[i]->next = right[i+1];
        if(l > 0)
            left[l-1]->next = (r > 0) ? right[0] : NULL;
        if(r > 0)
            right[r-1]->next = NULL;
        ListNode* ans = (l > 0) ? left[0] : right[0];
        return ans;
    }
};