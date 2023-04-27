#include <bits/stdc++.h>
#include "gondola.h"
#define maxn 100003
#define maxv 250001
#define mod 1000000009
using namespace std;
typedef long long LL;

int idx[maxv];
int init[maxn];

void calcInit(int n, int inputSeq[], int minIdx) {
	if(minIdx == -1)
		for( int i = 0 ; i < n ; i++ )
			init[i] = i+1;
	else
		for( int i = 0 ; i < n ; i++ ) {
			int d = (i-minIdx+n) % n;
			init[i] = inputSeq[minIdx]+d;
			if(init[i] > n)
				init[i] -= n;
		}
}

int valid(int n, int inputSeq[]) {
	int minIdx = -1;
	set<int> s;
	for( int i = 0 ; i < n ; i++ ) {
		if(s.find(inputSeq[i]) != s.end())
			return 0;
		s.insert(inputSeq[i]);
		if(inputSeq[i] <= n) {
			if(minIdx == -1 || inputSeq[i] < inputSeq[minIdx])
				minIdx = i;
		}
	}
	calcInit(n,inputSeq,minIdx);
	if(minIdx == -1)
		return 1;
	for( int i = 0 ; i < n ; i++ )
		if(inputSeq[i] <= n)
			if(init[i] != inputSeq[i])
				return 0;
	return 1;
}

int replacement(int n, int inputSeq[], int replacementSeq[]) {
	if(!valid(n,inputSeq))
		return 0;
	int maxIdx = -1;
	memset(idx,-1,sizeof(idx));
	for( int i = 0 ; i < n ; i++ ) {
		idx[inputSeq[i]] = i;
		if(maxIdx == -1 || inputSeq[i] > inputSeq[maxIdx])
			maxIdx = i;
	}
	int cnt = 0;
	int curr = init[maxIdx];
	int maxVal = inputSeq[maxIdx];
	for( int i = n+1 ; i <= maxVal ; i++ ) {
		if(idx[i] == -1 || i == maxVal) {
			replacementSeq[cnt++] = curr;
			curr = i;
		}
		else
			replacementSeq[cnt++] = init[idx[i]];
	}
	return cnt;
}

LL calcPow(LL x , int y) {
	if(y == 0)
		return 1;
	LL val = calcPow(x,y/2);
	val = (val*val) % mod;
	if(y & 1)
		val = (val*x) % mod;
	return val;
}

int countReplacement(int n, int inputSeq[]) {
	if(!valid(n,inputSeq))
		return 0;
	sort(inputSeq,inputSeq+n);
	int last = n;
	LL ans = 1;
	for( int i = 0 ; i < n ; i++ )
		if(inputSeq[i] > last) {
			int diff = inputSeq[i]-last-1;
			int base = n-i;
			last = inputSeq[i];
			LL mult = calcPow(base,diff);
			ans = (ans*mult) % mod;
		}
	if(inputSeq[0] > n)
		ans = (ans*n) % mod;
	return (int) ans;
}
