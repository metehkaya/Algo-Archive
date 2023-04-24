#include <bits/stdc++.h>
#define maxn 101
#define pb push_back
using namespace std;

int T,n;
int ar[maxn];
int cntEffect[4];
int firstIndex[2][2];

void solve3() {

}

void procEffect(int curr, int cntQ) {
	int effect = -1;
	for( int i = 0 ; i < 4 ; i++ )
		if( cntEffect[i] == cntQ )
			effect = i;
	for( int i = 1 ; i <= curr ; i++ ) {
		if(effect == 1)
			swap(ar[i], ar[n-i+1]);
		else if(effect == 2) {
			ar[i] = 1-ar[i];
			ar[n-i+1] = 1-ar[n-i+1];
		}
		else if(effect == 3) {
			swap(ar[i], ar[n-i+1]);
			ar[i] = 1-ar[i];
			ar[n-i+1] = 1-ar[n-i+1];
		}
	}
}

void seeEffect(int a, int b, int c, int d) {
	if(a == 0 && b == 0 && c == 0 && d == 0)
		cntEffect[0]++, cntEffect[1]++;
	else if(a == 0 && b == 0 && c == 1 && d == 1)
		cntEffect[2]++, cntEffect[3]++;
	else if(a == 0 && b == 1 && c == 0 && d == 1)
		cntEffect[0]++, cntEffect[3]++;
	else if(a == 0 && b == 1 && c == 1 && d == 0)
		cntEffect[1]++, cntEffect[2]++;
	else if(a == 1 && b == 0 && c == 1 && d == 0)
		cntEffect[0]++, cntEffect[3]++;
	else if(a == 1 && b == 0 && c == 0 && d == 1)
		cntEffect[1]++, cntEffect[2]++;
	else if(a == 1 && b == 1 && c == 1 && d == 1)
		cntEffect[0]++, cntEffect[1]++;
	else
		cntEffect[2]++, cntEffect[3]++;
}

void solve2() {
	for( int i = 1 ; i <= 5 ; i++ ) {
		printf("%d\n",i);
		fflush(stdout);
		scanf("%d",&ar[i]);
		printf("%d\n",n-i+1);
		fflush(stdout);
		scanf("%d",&ar[n-i+1]);
	}
	int curr = 5;
	while(curr < n/2) {
		memset(firstIndex, -1, sizeof(firstIndex));
		vector<int> queries;
		for( int i = 1 ; i <= curr ; i++ ) {
			int x = ar[i];
			int y = ar[n-i+1];
			if(firstIndex[x][y] == -1)
				firstIndex[x][y] = i, queries.pb(i);
		}
		int cntQ = (int) queries.size();
		memset(cntEffect, 0, sizeof(cntEffect));
		for( int i = 0 ; i < cntQ ; i++ ) {
			int newVal1, newVal2;
			int index = queries[i];
			int otherIndex = n-index+1;
			printf("%d\n",index);
			fflush(stdout);
			scanf("%d",&newVal1);
			printf("%d\n",otherIndex);
			fflush(stdout);
			scanf("%d",&newVal2);
			int oldVal1 = ar[index];
			int oldVal2 = ar[otherIndex];
			seeEffect(oldVal1, oldVal2, newVal1, newVal2);
		}
		procEffect(curr, cntQ);
		int rem = min( n/2 - curr , 5 - cntQ );
		for( int i = curr+1 ; i <= curr+rem ; i++ ) {
			printf("%d\n",i);
			fflush(stdout);
			scanf("%d",&ar[i]);
			printf("%d\n",n-i+1);
			fflush(stdout);
			scanf("%d",&ar[n-i+1]);
		}
		curr += rem;
	}
}

void solve1() {
	for( int i = 1 ; i <= n ; i++ ) {
		printf("%d\n",i);
		fflush(stdout);
		scanf("%d",&ar[i]);
	}
}

void reset() {
	memset(ar, -1, sizeof(ar));
}

int main() {
	scanf("%d%d",&T,&n);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		if(n == 10)
			solve1();
		else if(n == 20)
			solve2();
		else if(n == 100)
			solve3();
		for( int i = 1 ; i <= n ; i++ )
			printf("%d",ar[i]);
		puts("");
		fflush(stdout);
		string response;
		cin >> response;
		if(response == "N")
			break;
	}
	return 0;
}
