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
    map<int,int> mp;
    int dfs(TreeNode* node) {
        if(node == NULL)
            return 0;
        int val = node->val;
        val += dfs(node->left);
        val += dfs(node->right);
        mp[val]++;
        return val;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        int best = 0;
        vector<int> ans;
        map<int,int>::iterator it;
        for( it = mp.begin() ; it != mp.end() ; it++ ) {
            int val = it->first;
            int times = it->second;
            if(times > best) {
                best = times;
                ans.clear();
                ans.push_back(val);
            }
            else if(times == best)
                ans.push_back(val);
        }
        return ans;
    }
};