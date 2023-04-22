#include <bits/stdc++.h>
using namespace std;

struct Node {
	vector<Node*> child;
	Node() {
		child.resize(26,NULL);
	}
}*root;

int T,n;

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

void reset() {
	if(root != NULL) {
		queue<Node*> Q;
		Q.push(root);
		while(!Q.empty()) {
			Node* node = Q.front();
			Q.pop();
			for( int i = 0 ; i < 26 ; i++ )
				if(node->child[i] != NULL)
					Q.push(node->child[i]);
			delete node;
		}
	}
}

int main() {
	io();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		root = new Node();
		scanf("%d",&n);
		int ans = 0;
		for( int i = 0 ; i < n ; i++ ) {
			string s;
			cin >> s;
			int len = s.length();
			Node* node = root;
			bool found = false;
			for( int j = 0 ; j < len ; j++ ) {
				int c = s[j]-'a';
				if(node->child[c] == NULL) {
					node->child[c] = new Node();
					if(!found) {
						ans += j+1;
						found = true;
					}
				}
				node = node->child[c];
			}
			if(!found)
				ans += len;
		}
		printf("Case #%d: %d\n",tc,ans);
	}
	return 0;
}
