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
    vector<TreeNode*> f(int s, int e) {
        if(s > e)
            return {NULL};
        else if(s == e)
            return {new TreeNode(s)};
        vector<TreeNode*> res;
        for( int i = s ; i <= e ; i++ ) {
            vector<TreeNode*> l = f(s,i-1);
            vector<TreeNode*> r = f(i+1,e);
            for(auto lc : l)
                for(auto rc : r)
                    res.push_back(new TreeNode(i,lc,rc));
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans = f(1, n);
        return ans;
    }
};