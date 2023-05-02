#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef vector<double> vd;
typedef vector<vd> vvd;

int n;
int st[100];
double area1,area2;

double check(vd& a , vd& b , vd& c) {
	double x1 = a[0] , y1 = a[1];
	double x2 = b[0] , y2 = b[1];
	double x3 = c[0] , y3 = c[1];
	double dx1 = x3-x1 , dy1 = y3-y1;
	double dx2 = x2-x1 , dy2 = y2-y1;
	return dx1*dy2 - dx2*dy1;
}

double getarea(vvd& ar) {
	double sum = 0;
	int n = ar.size();
	for( int i = 0 ; i < n ; i++ ) {
		double x1 = ar[i][0];
		double y1 = ar[i][1];
		double x2 = ar[(i+1)%n][0];
		double y2 = ar[(i+1)%n][1];
		sum += x1*y2-x2*y1;
	}
	if(sum < 0)
		sum = -sum;
	return sum / 2.0;
}

bool comp(vd& a , vd& b) {
	if(a[2] != b[2])
		return a[2] < b[2];
	return a[3] < b[3];
}

void grahamscan(vvd& ar) {
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
	int cnt = 0;
	st[cnt++] = 0;
	for( int i = 1 ; i < n ; i++ ) {
		if(cnt == 1)
			st[cnt++] = i;
		else {
			while(cnt >= 2 && check(ar[st[cnt-2]],ar[st[cnt-1]],ar[i]) > 0)
				cnt--;
			st[cnt++] = i;
		}
	}
	vvd poly;
	for( int i = 0 ; i < cnt ; i++ )
		poly.pb(ar[st[i]]);
	area2 = getarea(poly);
}

int main() {
	for( int tc = 1 ; true ; tc++ ) {
		scanf("%d",&n);
		if(n == 0)
			break;
		vvd ar;
		for( int i = 0 ; i < n ; i++ ) {
			double x,y;
			scanf("%lf%lf",&x,&y);
			vd v;
			v.pb(x);
			v.pb(y);
			ar.pb(v);
		}
		area1 = getarea(ar);
		grahamscan(ar);
		double rem = area2 - area1;
		double p = 100.0 * rem / area2;
		printf("Tile #%d\n",tc);
		printf("Wasted Space = %.2lf %\n",p);
		puts("");
	}
	return 0;
}
