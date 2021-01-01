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
    bool dfs(TreeNode* node , ListNode* head) {
        if(head == NULL)
            return true;
        if(node == NULL)
            return false;
        if(node->val != head->val)
            return false;
        return dfs(node->left,head->next) or dfs(node->right,head->next);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(head == NULL)
            return true;
        if(root == NULL)
            return false;
        if( dfs(root,head) )
            return true;
        return isSubPath(head,root->left) or isSubPath(head,root->right);
    }
};