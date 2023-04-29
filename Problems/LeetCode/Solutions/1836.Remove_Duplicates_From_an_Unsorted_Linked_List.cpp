class Solution {
public:
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        unordered_map<int,int> mp;
        for( ListNode* node = head ; node ; node = node->next )
            mp[node->val]++;
        ListNode* ans = head;
        while(ans and mp[ans->val] > 1)
            ans = ans->next;
        if(!ans)
            return NULL;
        ListNode* tail = ans;
        for( ListNode* node = ans->next ; node ; node = node->next )
            if(mp[node->val] == 1) {
                tail->next = node;
                tail = node;
            }
        tail->next = NULL;
        return ans;
    }
};
