#include <bits/stdc++.h>
#define maxn 200000
using namespace std;

struct TreeNode {
	TreeNode* child[2];
	TreeNode() { child[0] = child[1] = NULL; }
};

int n,ans;
int ar[maxn];

void update(TreeNode* node , int k , int num) {
	if(k == -1)
		return;
	int way = (num & (1<<k)) > 0 ? 1 : 0;
	if(node->child[way] == NULL)
		node->child[way] = new TreeNode();
	update(node->child[way],k-1,num);
}

void query(TreeNode* node , int k , int num , int sum) {
	if(k == -1) {
		ans = max(ans,sum);
		return;
	}
	int way = (num & (1<<k)) > 0 ? 1 : 0;
	int add = (1<<k);
	if(node->child[!way] != NULL)
		query(node->child[!way],k-1,num,sum+add);
	else
		query(node->child[way],k-1,num,sum);
}

int main() {
	scanf("%d",&n);
	for( int i = 0 ; i < n ; i++ )
		scanf("%d",&ar[i]);
	TreeNode* root = new TreeNode();
	int curr = 0;
	for( int i = 0 ; i < n ; i++ ) {
		update(root,29,curr);
		curr = (curr ^ ar[i]);
		query(root,29,curr,0);
	}
	printf("%d\n",ans);
	return 0;
}