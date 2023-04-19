#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 300001
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> pi;

int N,r,c,n,m,ans;
int cnt,cntx,cnty;
int ar[maxn][2];
bool mxRow[maxn];
bool mxCol[maxn];
vector<pi> vr,vc;
map<int,int> cntr;
map<int,int> cntc;

int main() {
	scanf("%d%d%d",&r,&c,&N);
	for( int i = 0 , x,y ; i < N ; i++ ) {
		scanf("%d%d",&x,&y);
		ar[i][0] = x;
		ar[i][1] = y;
		cntr[x]++;
		cntc[y]++;
	}
	map<int,int>::iterator it;
	for( it = cntr.begin() ; it != cntr.end() ; it++ )
		vr.pb(pi(it->se,it->fi));
	for( it = cntc.begin() ; it != cntc.end() ; it++ )
		vc.pb(pi(it->se,it->fi));
	n = vr.size();
	m = vc.size();
	sort(vr.begin(),vr.end());
	sort(vc.begin(),vc.end());
	ans = vr[n-1].fi + vc[m-1].fi - 1;
	for( int i = n-1 ; i >= 0 ; i-- )
		if(vr[i].fi == vr[n-1].fi) {
			cntx++;
			mxRow[vr[i].se] = true;
		}
		else
			break;
	for( int i = m-1 ; i >= 0 ; i-- )
		if(vc[i].fi == vc[m-1].fi) {
			cnty++;
			mxCol[vc[i].se] = true;
		}
		else
			break;
	for( int i = 0 ; i < N ; i++ ) {
		int x = ar[i][0];
		int y = ar[i][1];
		if(mxRow[x] && mxCol[y])
			cnt++;
	}
	if(cnt < (LL)cntx*cnty)
		ans++;
	printf("%d\n",ans);
	return 0;
}
