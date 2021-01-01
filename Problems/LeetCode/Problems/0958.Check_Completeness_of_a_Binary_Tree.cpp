typedef vector<int> vi;
typedef vector<vi> vii;

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
    void dfs(TreeNode* node , int h , int id , vii& v) {
        if(v.size() == h)
            v.resize(h+1);
        id = (h > 6) ? -1 : id;
        v[h].push_back(id);
        if(node->left)
            dfs(node->left,h+1,id*2,v);
        if(node->right)
            dfs(node->right,h+1,id*2+1,v);
    }
    bool isCompleteTree(TreeNode* root) {
        vii v;
        dfs(root,0,1,v);
        int h = v.size();
        if(h > 7)
            return false;
        for( int i = 0 ; i < h-1 ; i++ )
            if(v[i].size() != (1<<i))
                return false;
        int k = h-1;
        int sz = v[k].size();
        return (v[k][0] == (1<<k)) and (v[k][sz-1] == (1<<k)+sz-1);
    }
};