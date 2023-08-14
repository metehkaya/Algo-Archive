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
    void f(priority_queue<int>& heap, priority_queue<int>& add, int k) {
        while(!add.empty()) {
            int val = add.top();
            add.pop();
            if(heap.size() == k and val >= heap.top())
                continue;
            if(heap.size() == k)
                heap.pop();
            heap.push(val);
        }
    }
    void dfs(TreeNode* node, priority_queue<int>& heap, int& ans , int k) {
        if(node->left) {
            priority_queue<int> add;
            dfs(node->left,add,ans,k);
            f(heap,add,k);
        }
        if(node->right) {
            priority_queue<int> add;
            dfs(node->right,add,ans,k);
            f(heap,add,k);
        }
        if(heap.size() == k and node->val > heap.top())
            ans++;
        heap.push(node->val);
    }
    int countGreatEnoughNodes(TreeNode* root, int k) {
        int ans = 0;
        priority_queue<int> heap;
        dfs(root,heap,ans,k);
        return ans;
    }
};
