#include <bits/stdc++.h>
#include "robots.h"
#define maxn 1050000
#define pb push_back
using namespace std;

struct item {
	int w,s,type;
	item(int _w , int _s , int _type) {
		w = _w;
		s = _s;
		type = _type;
	}
};

bool comp(const item& a , const item& b) {
	if(a.w != b.w)
		return a.w < b.w;
	return a.type > b.type;
}

int N,n,a,b;
vector<int> y;
vector<item> ar;

bool check(int d) {
	priority_queue<int> heap;
	for( int i = 0 ; i < N ; i++ ) {
		if(ar[i].type == 0)
			heap.push(ar[i].s);
		else {
			int cnt = d;
			while(cnt > 0 && !heap.empty()) {
				cnt--;
				heap.pop();
			}
		}
	}
	vector<int> v;
	while(!heap.empty()) {
		v.pb(heap.top());
		heap.pop();
	}
	reverse(v.begin(),v.end());
	int idx = 0 , vs = v.size();
	for( int i = 0 ; i < b ; i++ ) {
		int cnt = d;
		while(cnt > 0 && idx < vs && v[idx] < y[i]) {
			cnt--;
			idx++;
		}
	}
	return (idx == vs);
}

int putaway(int A, int B, int T, int X[], int Y[], int W[], int S[]) {
	a = A;
	b = B;
	n = T;
	N = n+a;
	for( int i = 0 ; i < b ; i++ )
		y.pb(Y[i]);
	sort(y.begin(),y.end());
	for( int i = 0 ; i < n ; i++ )
		ar.pb(item(W[i],S[i],0));
	for( int i = 0 ; i < a ; i++ )
		ar.pb(item(X[i],-1,1));
	sort(ar.begin(),ar.end(),comp);
	int l = 1 , r = n , ans = -1;
	while(l <= r) {
		int mid = (l+r)>>1;
		if(check(mid))
			ans = mid , r = mid-1;
		else
			l = mid+1;
	}
	return ans;
}

int main() {
	int a = 3 , b = 2 , t = 10;
	int x[3] = {6,2,9};
	int y[2] = {4,7};
	int w[10] = {4,8,2,7,1,5,3,8,7,10};
	int s[10] = {6,5,3,9,8,1,3,7,6,5};
	printf("%d\n",putaway(a,b,t,x,y,w,s));
	return 0;
}
