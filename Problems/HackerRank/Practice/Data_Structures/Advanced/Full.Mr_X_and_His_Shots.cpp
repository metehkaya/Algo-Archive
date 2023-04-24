#include <bits/stdc++.h>
#define maxn 100000
#define pb push_back
using namespace std;
typedef long long LL;

struct data {
	int x,type,id;
};

bool comp1( data a , data b ) {
	if( a.x != b.x )
		return a.x < b.x;
	return a.type > b.type;
}

bool comp2( data a , data b ) {
	if( a.x != b.x )
		return a.x > b.x;
	return a.type > b.type;
}

data getData( int _x , int _type , int _id ) {
	data d;
	d.x = _x;
	d.type = _type;
	d.id = _id;
	return d;
}

LL ans;
int n,m;
int a[maxn];
int b[maxn];
int c[maxn];
int d[maxn];
int minuss[maxn];
vector<data> v1,v2;

int main() {
	scanf("%d%d",&n,&m);
	for( int i = 0 ; i < n ; i++ ) {
		scanf("%d%d",&a[i],&b[i]);
		v1.pb(getData(b[i],0,i));
		v2.pb(getData(a[i],0,i));
	}
	for( int i = 0 ; i < m ; i++ ) {
		scanf("%d%d",&c[i],&d[i]);
		v1.pb(getData(c[i],1,i));
		v2.pb(getData(d[i],1,i));
	}
	sort(v1.begin(),v1.end(),comp1);
	for( int i = 0 , cnt = 0 ; i < n+m ; i++ ) {
		if(v1[i].type == 0)
			cnt++;
		else
			minuss[v1[i].id] += cnt;
	}
	sort(v2.begin(),v2.end(),comp2);
	for( int i = 0 , cnt = 0 ; i < n+m ; i++ ) {
		if(v2[i].type == 0)
			cnt++;
		else
			minuss[v2[i].id] += cnt;
	}
	for( int i = 0 ; i < m ; i++ )
		ans += n-minuss[i];
	printf("%lld\n",ans);
	return 0;
}
