struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode *ans = NULL , *tail;
        for( int i = 1 ; head != NULL ; i++ ) {
            vector<int> v;
            for( int j = 0 ; head != NULL && j < i ; j++ ) {
                v.push_back(head->val);
                head = head->next;
            }
            int sz = v.size();
            if(sz%2 == 0)
                reverse(v.begin(),v.end());
            if(i == 1) {
                ans = new ListNode(v[0]);
                tail = ans;
            }
            else
                for( int j = 0 ; j < sz ; j++ ) {
                    tail->next = new ListNode(v[j]);
                    tail = tail->next;
                }
        }
        return ans;
    }
};
