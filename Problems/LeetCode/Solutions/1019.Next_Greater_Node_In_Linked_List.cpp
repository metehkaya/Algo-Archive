struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ar;
        while(head != NULL) {
            ar.push_back(head->val);
            head = head->next;
        }
        int n = ar.size();
        stack<int> st;
        vector<int> ans(n);
        for( int i = n-1 ; i >= 0 ; i-- ) {
            while(!st.empty() && ar[st.top()] <= ar[i])
                st.pop();
            ans[i] = st.empty() ? 0 : ar[st.top()];
            st.push(i);
        }
        return ans;
    }
};