struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* f(int l , int r , vector<int>& v) {
        if(l > r)
            return NULL;
        int mid = (l+r) >> 1;
        TreeNode* node = new TreeNode(v[mid]);
        node->left = f(l,mid-1,v);
        node->right = f(mid+1,r,v);
        return node;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> v;
        while(head != NULL) {
            v.push_back(head->val);
            head = head->next;
        }
        int n = v.size();
        return f(0,n-1,v);
    }
};