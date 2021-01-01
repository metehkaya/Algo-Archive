struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> nodes;
        while(head != NULL) {
            nodes.push_back(head);
            head = head->next;
        }
        vector<ListNode*> finalList;
        int n = nodes.size();
        for( int i = 0 , j = n-1 ; i <= j ; ) {
            finalList.push_back(nodes[i++]);
            if(i <= j)
                finalList.push_back(nodes[j--]);
        }
        for( int i = 1 ; i < n ; i++ )
            finalList[i-1]->next = finalList[i];
        if(n) {
            finalList[n-1]->next = NULL;
            head = finalList[0];
        }
    }
};