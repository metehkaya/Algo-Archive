/*
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
*/

class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        int num = 0;
        ListNode* node = head;
        vector<int> v;
        while(node) {
            v.push_back(node->val);
            node = node->next;
        }
        vector<int> v2;
        int len = v.size() , add = 0;
        for( int i = len-1 ; i >= 0 or add > 0 ; i-- ) {
            int num = add;
            add = 0;
            if(i >= 0)
                num += 2*v[i];
            if(num >= 10)
                num -= 10 , add = 1;
            v2.push_back(num);
        }
        reverse(v2.begin(),v2.end());
        ListNode* ans = new ListNode();
        ListNode* tail = ans;
        bool first = true;
        for(int num : v2) {
            if(first)
                tail->val = num;
            else {
                tail->next = new ListNode(num);
                tail = tail->next;
            }
            first = false;
        }
        return ans;
    }
};