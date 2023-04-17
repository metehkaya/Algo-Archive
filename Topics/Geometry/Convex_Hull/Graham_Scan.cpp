#include <bits/stdc++.h>
#define maxn 100000
#define pb push_back
using namespace std;
typedef vector<double> vd;
typedef vector<vd> vvd;

int n,stcnt;
int st[maxn];
vvd ar;

double check(vd& a , vd& b , vd& c) {
	double x1 = a[0] , y1 = a[1];
	double x2 = b[0] , y2 = b[1];
	double x3 = c[0] , y3 = c[1];
	double dx1 = x3-x1 , dy1 = y3-y1;
	double dx2 = x2-x1 , dy2 = y2-y1;
	return dx1*dy2 - dx2*dy1;
}

bool comp(vd& a , vd& b) {
	if(a[2] != b[2])
		return a[2] < b[2];
	return a[3] < b[3];
}

void grahamscan() {
	int idx = 0;
	for( int i = 1 ; i < n ; i++ )
		if(ar[i][1] < ar[idx][1] || (ar[i][1] == ar[idx][1] && ar[i][0] < ar[idx][0]))
			idx = i;
	swap(ar[0],ar[idx]);
	for( int i = 1 ; i < n ; i++ ) {
		double dx = ar[i][0]-ar[0][0];
		double dy = ar[i][1]-ar[0][1];
		ar[i].push_back(atan2(dy,dx));
		ar[i].push_back(dx*dx+dy*dy);
	}
	sort(ar.begin()+1 , ar.end() , comp);
	st[stcnt++] = 0;
	for( int i = 1 ; i < n ; i++ ) {
		if(stcnt == 1)
			st[stcnt++] = i;
		else {
			while(stcnt >= 2 && check(ar[st[stcnt-2]],ar[st[stcnt-1]],ar[i]) > 0)
				stcnt--;
			st[stcnt++] = i;
		}
	}
}

int main() {
	scanf("%d",&n);
	for( int i = 0 ; i < n ; i++ ) {
		double x,y;
		scanf("%lf%lf",&x,&y);
		vd v;
		v.pb(x);
		v.pb(y);
		ar.pb(v);
	}
	grahamscan();
	printf("%d\n",stcnt);
	for( int i = 0 ; i < stcnt ; i++ )
		printf("%lf %lf\n",ar[st[i]][0],ar[st[i]][1]);
	return 0;
}
