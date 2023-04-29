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
    void dfs(TreeNode* node , vector<int>& v , int& idx , bool change) {
        if(node->left)
            dfs(node->left,v,idx,change);
        if(change)
            node->val = v[idx++];
        else
            v.push_back(node->val);
        if(node->right)
            dfs(node->right,v,idx,change);
    }
    void recoverTree(TreeNode* root) {
        int idx = 0;
        vector<int> v;
        dfs(root,v,idx,false);
        int n = v.size() , x=-1 , y=-1;
        for( int i = 0 ; i < n-1 ; i++ )
            if(v[i] > v[i+1]) {
                if(x == -1)
                    x = i;
                y = i+1;
            }
        swap(v[x],v[y]);
        dfs(root,v,idx,true);
    }
};