struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& ar) {
        int n = ar.size();
        set<int> nums;
        for( int i = 0 ; i < n ; i++ )
            nums.insert(ar[i]);
        int ans = 0;
        bool active = false;
        ListNode* node = head;
        while(node != NULL) {
            bool exists = (nums.find(node->val) != nums.end());
            if(active) {
                if(!exists)
                    active = false;
            }
            else {
                if(exists)
                    ans++ , active = true;
            }
            node = node->next;
        }
        return ans;
    }
};