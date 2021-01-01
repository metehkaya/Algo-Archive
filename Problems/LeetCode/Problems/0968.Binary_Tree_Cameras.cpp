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
    const int maxv = 1005;
    void dfs(TreeNode* node , int id , int& n , vi& l , vi& r) {
        l.resize(n);
        r.resize(n);
        l[id] = r[id] = -1;
        if(node->left) {
            l[id] = n++;
            dfs(node->left,l[id],n,l,r);
        }
        if(node->right) {
            r[id] = n++;
            dfs(node->right,r[id],n,l,r);
        }
    }
    int f(int u , bool dad , bool col , vi& l , vi& r , vii& dp) {
        if(l[u] == -1 and r[u] == -1) {
            if(dad or col)
                return 0;
            else
                return maxv;
        }
        int st = 2*dad+col;
        if(dp[u][st] != -1)
            return dp[u][st];
        dp[u][st] = maxv;
        for( int i = 0 ; i < 2 ; i++ )
            for( int j = 0 ; j < 2 ; j++ ) {
                if(i == 1 and l[u] == -1)
                    continue;
                if(j == 1 and r[u] == -1)
                    continue;
                if(!dad and !col and i == 0 and j == 0)
                    continue;
                int sum = 0;
                if(l[u] != -1)
                    sum += f(l[u],col,i,l,r,dp) + i;
                if(r[u] != -1)
                    sum += f(r[u],col,j,l,r,dp) + j;
                dp[u][st] = min( dp[u][st] , sum );
            }
        return dp[u][st];
    }
    int minCameraCover(TreeNode* root) {
        int n = 1;
        vi l,r;
        dfs(root,0,n,l,r);
        vii dp(n,vi(4,-1));
        return min( f(0,0,0,l,r,dp) , f(0,0,1,l,r,dp)+1 );
    }
};