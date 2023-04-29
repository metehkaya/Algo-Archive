typedef vector<int> vi;

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
    TreeNode* solve(vi& io, vi& po, map<int,int>& id, int ix, int iy, int px, int py) {
        int idx = id[po[py]];
        int l = idx-ix;
        int r = iy-idx;
        TreeNode* node = new TreeNode(io[idx]);
        if(l)
            node->left = solve(io,po,id,ix,idx-1,px,px+l-1);
        if(r)
            node->right = solve(io,po,id,idx+1,iy,px+l,py-1);
        return node;
    }
    TreeNode* buildTree(vi& io, vi& po) {
        int n = io.size();
        if(n == 0)
            return NULL;
        map<int,int> id;
        for( int i = 0 ; i < n ; i++ )
            id[io[i]] = i;
        return solve(io,po,id,0,n-1,0,n-1);
    }
};