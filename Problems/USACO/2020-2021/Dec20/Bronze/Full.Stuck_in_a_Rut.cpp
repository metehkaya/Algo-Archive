#include <bits/stdc++.h>
#define maxn 50
using namespace std;

struct cow {
	int x,y,id;
	char type;
	int last;
} ar[maxn];

int n;

bool comp1(const cow& a , const cow& b) {
	return a.x + a.y > b.x + b.y;
}

bool comp2(const cow& a , const cow& b) {
	return a.id < b.id;
}

int main() {
	scanf("%d",&n);
	for( int i = 0 ; i < n ; i++ ) {
		string s;
		cin >> s >> ar[i].x >> ar[i].y;
		ar[i].type = s[0];
		ar[i].id = i;
	}
	sort(ar,ar+n,comp1);
	for( int i = 0 , j = 0 ; i < n ; i = j ) {
		while(j < n && ar[i].x + ar[i].y == ar[j].x + ar[j].y)
			j++;
		for( int k = i ; k < j ; k++ ) {
			ar[k].last = INT_MAX;
			for( int l = 0 ; l < i ; l++ ) {
				if(ar[k].type == 'E' && ar[l].type == 'E') {
					if(ar[k].y == ar[l].y)
						ar[k].last = min(ar[k].last,ar[l].x);
				}
				else if(ar[k].type == 'E' && ar[l].type == 'N') {
					if(ar[l].y <= ar[k].y && ar[l].last > ar[k].y)
						ar[k].last = min(ar[k].last,ar[l].x);
				}
				else if(ar[k].type == 'N' && ar[l].type == 'N') {
					if(ar[k].x == ar[l].x)
						ar[k].last = min(ar[k].last,ar[l].y);
				}
				else {
					if(ar[l].x <= ar[k].x && ar[l].last > ar[k].x)
						ar[k].last = min(ar[k].last,ar[l].y);
				}
			}
			// printf("[%d] : %d %d %c : %d\n",ar[k].id,ar[k].x,ar[k].y,ar[k].type,ar[k].last);
		}
	}
	sort(ar,ar+n,comp2);
	for( int i = 0 ; i < n ; i++ ) {
		if(ar[i].last == INT_MAX)
			puts("Infinity");
		else if(ar[i].type == 'E')
			printf("%d\n",ar[i].last-ar[i].x);
		else
			printf("%d\n",ar[i].last-ar[i].y);
	}
	return 0;
}
