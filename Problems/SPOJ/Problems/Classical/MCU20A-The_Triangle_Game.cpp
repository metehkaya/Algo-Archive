#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int perm[6];
int head[6];
int ar[6][3];
vector<int> masks[601];

void reset() {
	for( int i = 6 ; i <= 600 ; i++ )
		masks[i].clear();
}

void f(int idx , int mask , int sum) {
	if(idx == 6) {
		masks[sum].pb(mask);
		return;
	}
	for( int i = 0 ; i < 3 ; i++ )
		f(idx+1,3*mask+i,sum+ar[idx][i]);
}

bool check() {
	for( int i = 0 ; i < 6 ; i++ )
		perm[i] = i;
	do {
		bool ok = true;
		for( int i = 0 ; i < 6 ; i++ ) {
			int pi = perm[i];
			int pj = perm[(i+1)%6];
			int idxi = (head[pi]+1)%3;
			int idxj = (head[pj]+2)%3;
			if(ar[pi][idxi] != ar[pj][idxj]) {
				ok = false;
				break;
			}
		}
		if(ok)
			return true;
	}while(next_permutation(perm+1,perm+6));
	return false;
}

int main() {
	string op;
	do {
		reset();
		for( int i = 0 ; i < 6 ; i++ )
			for( int j = 0 ; j < 3 ; j++ )
				scanf("%d",&ar[i][j]);
		f(0,0,0);
		bool found = false;
		for( int sum = 600 ; sum >= 6 && !found ; sum-- ) {
			int sz = masks[sum].size();
			for( int i = 0 ; i < sz ; i++ ) {
				int mask = masks[sum][i];
				for( int j = 5 ; j >= 0 ; j-- ) {
					head[j] = mask % 3;
					mask /= 3;
				}
				if(check()) {
					printf("%d\n",sum);
					found = true;
					break;
				}
			}
		}
		if(!found)
			puts("none");
		cin >> op;
	}while(op == "*");
	return 0;
}
