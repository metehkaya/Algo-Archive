#define fi first
#define se second
typedef pair<int,int> pi;

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
    pi dfs(TreeNode* node, int& ans) {
        if(node == NULL)
            return pi(0,0);
        int sum = node->val;
        int cnt = 1;
        pi l = dfs(node->left,ans);
        pi r = dfs(node->right,ans);
        sum += l.fi + r.fi;
        cnt += l.se + r.se;
        if(node->val == sum/cnt)
            ans++;
        return pi(sum,cnt);
    }
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        dfs(root,ans);
        return ans;
    }
};
