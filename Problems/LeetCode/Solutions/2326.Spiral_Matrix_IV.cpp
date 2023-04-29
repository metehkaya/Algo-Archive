#define fi first
#define se second
#define pb push_back
typedef pair<int,int> pi;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    vector<vector<int>> spiralMatrix(int n, int m, ListNode* head) {
        vector<vector<int>> ans(n,vector<int>(m,-1));
        vector<vector<bool>> mark(n,vector<bool>(m,false));
        vector<pi> v;
        v.pb(pi(0,0));
        int dir = 0;
        while(v.size() < n*m) {
            pi pos = v.back();
            int r = pos.fi;
            int c = pos.se;
            mark[r][c] = true;
            while(true) {
                int x = r + dirs[dir][0];
                int y = c + dirs[dir][1];
                if(x < 0 || x >= n || y < 0 || y >= m) {
                    dir = (dir+1) % 4;
                    continue;
                }
                if(mark[x][y]) {
                    dir = (dir+1) % 4;
                    continue;
                }
                v.push_back(pi(x,y));
                break;
            }
        }
        int idx = 0;
        while(head != NULL) {
            int val = head->val;
            ans[v[idx].fi][v[idx].se] = val;
            idx++;
            head = head->next;
        }
        return ans;
    }
};
