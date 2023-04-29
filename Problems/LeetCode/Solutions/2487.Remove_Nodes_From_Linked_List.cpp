struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        vector<int> v;
        ListNode* node = head;
        while(node != NULL) {
            v.push_back(node->val);
            node = node->next;
        }
        int n = v.size();
        for( int i = n-1 , mx = -1 ; i >= 0 ; i-- ) {
            if(v[i] < mx)
                v[i] = -1;
            else
                mx = v[i];
        }
        head = NULL;
        ListNode* tail = NULL;
        for( int i = 0 ; i < n ; i++ )
            if(v[i] > 0) {
                ListNode* node = new ListNode(v[i]);
                if(head == NULL)
                    head = tail = node;
                else {
                    tail->next = node;
                    tail = node;
                }
            }
        return head;
    }
};
