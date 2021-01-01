struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void dfs(TreeNode* node, TreeNode* p, TreeNode* q, vector<TreeNode*>& chainP, vector<TreeNode*>& chainQ) {
        if(chainP.empty() || chainP.back() != p)
            chainP.push_back(node);
        if(chainQ.empty() || chainQ.back() != q)
            chainQ.push_back(node);
        if(chainP.back() == p && chainQ.back() == q)
            return;
        if(node->left != NULL)
            dfs(node->left, p, q, chainP, chainQ);
        if(node->right != NULL)
            dfs(node->right, p, q, chainP, chainQ);
        if(chainP.back() != p)
            chainP.pop_back();
        if(chainQ.back() != q)
            chainQ.pop_back();
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> chainP;
        vector<TreeNode*> chainQ;
        dfs(root,p,q,chainP,chainQ);
        int mn = min(chainP.size(), chainQ.size());
        for( int i = mn-1 ; i >= 1 ; i-- )
            if( chainP[i] == chainQ[i] )
                return chainP[i];
        return root;
    }
};