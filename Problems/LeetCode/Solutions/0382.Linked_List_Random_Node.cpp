struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int n = 0;
    vector<int> v;
    Solution(ListNode* head) {
        ListNode* curr = head;
        while(curr != NULL) {
            n++;
            v.push_back(curr->val);
            curr = curr->next;
        }
    }
    int getRandom() {
        int idx = rand() % n;
        return v[idx];
    }
};