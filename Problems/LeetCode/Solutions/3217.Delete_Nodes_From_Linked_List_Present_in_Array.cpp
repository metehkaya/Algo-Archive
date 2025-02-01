struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> valuesToRemove(nums.begin(), nums.end());
        while(head != NULL && valuesToRemove.count(head->val) > 0) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
        if(head == NULL)
            return NULL;
        ListNode* current = head;
        while(current->next != NULL) {
            if(valuesToRemove.contains(current->next->val)) {
                ListNode* temp = current->next;
                current->next = current->next->next;
                delete temp;
            }
            else
                current = current->next;
        }
        return head;
    }
};