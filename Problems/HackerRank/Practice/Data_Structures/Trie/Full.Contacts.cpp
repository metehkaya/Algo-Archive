#include <bits/stdc++.h>
#define maxs 22
#define maxt 100000
using namespace std;

int T,n;
char q[5];
char str[maxs];
int tree[maxt*maxs];
int nextId[maxt*maxs][26];

void update(int id , int index) {
	tree[id]++;
	if(index == strlen(str))
		return;
	int way = str[index] - 'a';
	if(!nextId[id][way])
		nextId[id][way] = ++n;
	update(nextId[id][way],index+1);
}

int query( int id , int index ) {
	if(index == strlen(str))
		return tree[id];
	int way = str[index] - 'a';
	if(!nextId[id][way])
		return 0;
	return query(nextId[id][way],index+1);
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%s%s",q,str);
		if(q[0] == 'a')
			update(0,0);
		else
			printf("%d\n",query(0,0));
	}
	return 0;
}
