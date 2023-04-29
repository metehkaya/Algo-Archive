struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || k == 1)
            return head;
        vector<ListNode*> chain;
        int cnt = 0;
        ListNode* newHead = head;
        ListNode* nextNode = NULL;
        ListNode* firstNodeThisChain = NULL;
        ListNode* firstNodePrevChain = NULL;
        for( ListNode* curr = head ; curr != NULL ; curr = nextNode , cnt++ ) {
            nextNode = curr->next;
            if(cnt % k == 0) {
                chain.clear();
                firstNodePrevChain = firstNodeThisChain;
                firstNodeThisChain = curr;
                if(firstNodePrevChain != NULL)
                    firstNodePrevChain->next = curr;
            }
            chain.push_back(curr);
            if(cnt % k == k-1) {
                for( int i = 1 ; i < k ; i++ )
                    chain[i]->next = chain[i-1];
                if(newHead == head)
                    newHead = chain[k-1];
                if(firstNodePrevChain != NULL)
                    firstNodePrevChain->next = chain[k-1];
            }
        }
        if(cnt % k == 0)
            firstNodeThisChain->next = NULL;
        return newHead;
    }
};