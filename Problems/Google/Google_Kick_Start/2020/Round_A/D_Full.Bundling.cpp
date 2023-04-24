#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct Node {
	int cnt;
	map<char,Node*> hashh;
	Node() {cnt=0;}
};

LL ans;
int T,n,k;

LL query(Node* node, bool isRoot) {
	LL ans = 0;
	if(!isRoot)
		ans += node->cnt/k;
	map<char,Node*>::iterator mit = node->hashh.begin();
	while(mit != node->hashh.end()) {
		ans += query(mit->second, false);
		mit++;
	}
	return ans;
}

void update(Node* node, string& word, int index) {
	if(index != 0)
		node->cnt++;
	if(index == (int) word.length())
		return;
	map<char,Node*>::iterator mit = node->hashh.find(word[index]);
	if(mit == node->hashh.end())
		node->hashh.insert(make_pair(word[index], new Node()));
	update(node->hashh[word[index]], word, index+1);
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		ans = 0;
		Node* root = new Node();
		scanf("%d%d",&n,&k);
		for( int i = 0 ; i < n ; i++ ) {
			string word;
			cin >> word;
			update(root, word, 0);
		}
		printf("Case #%d: %lld\n", tc, query(root, true));
	}
	return 0;
}
