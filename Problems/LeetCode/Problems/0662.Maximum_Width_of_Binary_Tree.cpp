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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        queue<pair<TreeNode*,int>> Q;
        Q.push(make_pair(root,0));
        int ans = 0;
        while(!Q.empty()) {
            int n = Q.size();
            if(n == 1)
                Q.front().second = 0;
            int mn = -1 , mx = -1;
            for( int i = 0 ; i < n ; i++ ) {
                TreeNode* node = Q.front().first;
                int idx = Q.front().second;
                Q.pop();
                if(i == 0)
                    mn = idx;
                if(i == n-1) {
                    mx = idx;
                    ans = max(ans,mx-mn+1);
                }
                if(node->left != NULL)
                    Q.push(make_pair(node->left,2*idx));
                if(node->right != NULL)
                    Q.push(make_pair(node->right,2*idx+1));
            }
        }
        return ans;
    }
};