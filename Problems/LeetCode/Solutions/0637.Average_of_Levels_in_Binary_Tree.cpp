class Solution {
public:
    void dfs(TreeNode* node , int lvl , vector<double>& sum , vector<double>& cnt) {
        if(sum.size() == lvl) {
            cnt.push_back(1);
            sum.push_back(node->val);
        }
        else {
            cnt[lvl]++;
            sum[lvl] += node->val;
        }
        if(node->left)
            dfs(node->left,lvl+1,sum,cnt);
        if(node->right)
            dfs(node->right,lvl+1,sum,cnt);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> sum,cnt;
        dfs(root,0,sum,cnt);
        int h = sum.size();
        for( int i = 0 ; i < h ; i++ )
            sum[i] /= cnt[i];
        return sum;
    }
};