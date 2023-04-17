#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int val,cnt;
	Node *l,*r;
	Node(int val) {
		cnt = 1;
		this->val = val;
		l = r = NULL;
	}
};

int n,m;

void update(Node*& node , int val) {
	if(node == NULL) {
		node = new Node(val);
		return;
	}
	if(node->val == val) {
		node->cnt++;
		return;
	}
	if(val < node->val)
		update(node->l,val);
	else
		update(node->r,val);
}

int query(Node* node , int val) {
	int res;
	if(node == NULL)
		res = 0;
	else if(node->val == val)
		res = node->cnt;
	else if(val < node->val)
		res = query(node->l,val);
	else
		res = query(node->r,val);
	return res;
}

int main() {
	Node* root = NULL;
	scanf("%d%d",&n,&m);
	for( int i = 0 , x ; i < n ; i++ ) {
		scanf("%d",&x);
		update(root,x);
	}
	for( int i = 0 , x ; i < m ; i++ ) {
		scanf("%d",&x);
		printf("%d\n",query(root,x));
	}
	return 0;
}
