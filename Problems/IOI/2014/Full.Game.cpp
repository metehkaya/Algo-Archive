#include <bits/stdc++.h>
#include "game.h"
#define maxn 1500
using namespace std;

int cnt[maxn];

void initialize(int n) {
	memset(cnt,0,sizeof(cnt));
}

int hasEdge(int u, int v) {
	u = max(u,v);
	return u == (++cnt[u]);
}
