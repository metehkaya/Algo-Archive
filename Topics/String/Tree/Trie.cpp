#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int cnt;
	Node* nxt[26];
	Node() {
		cnt = 0;
		for( int i = 0 ; i < 26 ; i++ )
			nxt[i] = NULL;
	}
};

int n,m;

void update(int idx , int len , string& s , Node* node) {
	node->cnt++;
	if(idx == len)
		return;
	int k = s[idx]-'a';
	if(node->nxt[k] == NULL)
		node->nxt[k] = new Node();
	update(idx+1,len,s,node->nxt[k]);
}

int query(int idx , int len , string& s , Node* node) {
	if(node == NULL)
		return 0;
	if(idx == len)
		return node->cnt;
	int k = s[idx]-'a';
	return query(idx+1,len,s,node->nxt[k]);
}

int main() {
	Node* root = new Node();
	scanf("%d%d",&n,&m);
	for( int i = 0 ; i < n ; i++ ) {
		string s;
		cin >> s;
		int len = s.length();
		update(0,len,s,root);
	}
	for( int i = 0 ; i < m ; i++ ) {
		string s;
		cin >> s;
		int len = s.length();
		int ans = query(0,len,s,root);
		printf("%d\n",ans);
	}
	return 0;
}
