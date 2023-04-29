struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int l, int r) {
        if(l == r)
            return head;
        vector<ListNode*> nodes;
        ListNode* node = head;
        for( int i = 1 ; node != NULL ; i++ , node = node->next )
            nodes.push_back(node);
        l--,r--;
        int m = (l+r)/2;
        for( int i = 0 ; l+i <= m ; i++ )
            swap(nodes[l+i]->val,nodes[r-i]->val);
        return nodes[0];
    }
};