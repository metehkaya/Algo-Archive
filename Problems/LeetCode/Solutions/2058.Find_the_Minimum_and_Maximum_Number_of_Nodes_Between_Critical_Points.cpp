struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> vals;
        while(head != NULL) {
            vals.push_back(head->val);
            head = head->next;
        }
        int n = vals.size();
        vector<int> v;
        for( int i = 1 ; i < n-1 ; i++ )
            if(vals[i] > max(vals[i-1],vals[i+1]) || vals[i] < min(vals[i-1],vals[i+1]))
                v.push_back(i);
        vector<int> ans(2,-1);
        int sz = v.size();
        if(sz >= 2) {
            ans[0] = ans[1] = v[sz-1]-v[0];
            for( int i = 1 ; i < sz ; i++ )
                ans[0] = min(ans[0],v[i]-v[i-1]);
        }
        return ans;
    }
};
