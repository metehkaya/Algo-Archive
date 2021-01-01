struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = NULL;
        ListNode* tail = NULL;
        set<pair<int,int>> heap;
        set<pair<int,int>>::iterator iter;
        int n = (int) lists.size();
        for( int i = 0 ; i < n ; i++ )
            if(lists[i] != NULL)
                heap.insert(make_pair(lists[i]->val,i));
        while(!heap.empty()) {
            iter = heap.begin();
            int value = iter->first;
            int id = iter->second;
            heap.erase(iter);
            if(head == NULL)
                head = tail = lists[id];
            else {
                tail->next = lists[id];
                tail = tail->next;
            }
            lists[id] = lists[id]->next;
            if(lists[id] != NULL)
                heap.insert(make_pair(lists[id]->val,id));
        }
        return head;
    }
};