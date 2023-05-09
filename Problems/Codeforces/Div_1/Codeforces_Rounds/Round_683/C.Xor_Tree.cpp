#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long LL;

struct Node {
	int cnt;
	Node *child[2];
	Node() {
		cnt = 0;
		child[0] = child[1] = NULL;
	}
}*root;

int n;

int solve(Node* node , int k) {
	if(node == NULL)
		return 0;
	if(k == -1 || node->cnt == 1)
		return 1;
	int l = (node->child[0] != NULL) ? node->child[0]->cnt : 0;
	int r = (node->child[1] != NULL) ? node->child[1]->cnt : 0;
	if(l >= 1 && r >= 1)
		return max( solve(node->child[0],k-1) , solve(node->child[1],k-1) ) + 1;
	return solve(node->child[0],k-1) + solve(node->child[1],k-1);
}

int main() {
	root = new Node();
	scanf("%d",&n);
	for( int i = 0 , val ; i < n ; i++ ) {
		scanf("%d",&val);
		Node* node = root;
		node->cnt++;
		for( int k = 29 ; k >= 0 ; k-- ) {
			int way = ((val & (1<<k)) > 0);
			if(node->child[way] == NULL)
				node->child[way] = new Node();
			node = node->child[way];
			node->cnt++;
		}
	}
	printf("%d\n",n-solve(root,29));
	return 0;
}
