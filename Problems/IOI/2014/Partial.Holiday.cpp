#include <bits/stdc++.h>
#include "holiday.h"
#define maxn 100003
#define pb push_back
using namespace std;
typedef long long LL;

struct city {
	int val,id,ord;
}ar[maxn];

bool comp1(const city& a , const city& b) {
	return a.val < b.val;
}

bool comp2(const city& a , const city& b) {
	return a.id < b.id;
}

LL sum[4*maxn];
int cnt[4*maxn];

void update(int cx , int cy , int q , int val1 , int val2 , int id) {
	if(cy < q || q < cx)
		return;
	if(cx == cy) {
		cnt[id] = max(cnt[id]+val1,0);
		sum[id] = max(sum[id]+val2,0LL);
		return;
	}
	int mid = (cx+cy) >> 1;
	update(cx,mid,q,val1,val2,2*id);
	update(mid+1,cy,q,val1,val2,2*id+1);
	cnt[id] = cnt[2*id] + cnt[2*id+1];
	sum[id] = sum[2*id] + sum[2*id+1];
}

LL query(int x , int y , int& rem , int id) {
	if(rem >= cnt[id]) {
		rem -= cnt[id];
		return sum[id];
	}
	if(x == y)
		return 0;
	int mid = (x+y) >> 1;
	LL res = query(mid+1,y,rem,2*id+1);
	if(rem > 0)
		res += query(x,mid,rem,2*id);
	return res;
}

LL findMaxAttraction(int n, int s, int d, int arr[]) {
	for( int i = 0 ; i < n ; i++ ) {
		ar[i].val = arr[i];
		ar[i].id = i;
	}
	sort(ar,ar+n,comp1);
	for( int i = 0 ; i < n ; i++ )
		ar[i].ord = i;
	sort(ar,ar+n,comp2);
	LL ans = 0;
	for( int l = s ; l >= 0 && l >= s-d ; l-- ) {
		for( int i = s+1 ; i < n ; i++ )
			update(0,n-1,ar[i].ord,-1,-ar[i].val,1);
		update(0,n-1,ar[l].ord,1,ar[l].val,1);
		int rem = d-(s-l);
		LL val = query(0,n-1,rem,1);
		ans = max(ans,val);
		for( int i = s+1 ; i < n ; i++ ) {
			int dx = s-l , dy = i-s;
			int rem = d - (dx+dy) - min(dx,dy);
			if(rem <= 0)
				break;
			update(0,n-1,ar[i].ord,1,ar[i].val,1);
			LL val = query(0,n-1,rem,1);
			ans = max(ans,val);
		}
	}
	return ans;
}
