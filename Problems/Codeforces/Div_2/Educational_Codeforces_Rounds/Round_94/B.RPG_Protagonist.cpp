#include <bits/stdc++.h>
using namespace std;

int T,p,f,cs,cw,s,w;

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%d%d%d%d%d",&p,&f,&cs,&cw,&s,&w);
		if(s > w) {
			swap(s,w);
			swap(cs,cw);
		}
		int ans = 0;
		for( int i = 0 ; i <= min(cs,p/s) ; i++ ) {
			int res = i;
			int P=p,F=f,CS=cs,CW=cw,S=s,W=w;
			P -= i*S , CS -= i;
			int mn = min(P/W,CW);
			res += mn;
			P -= mn*W , CW -= mn;
			mn = min(F/S,CS);
			res += mn;
			F -= mn*S , CS -= mn;
			mn = min(F/W,CW);
			res += mn;
			F -= mn*W , CW -= mn;
			ans = max(ans,res);
		}
		printf("%d\n",ans);
	}
	return 0;
}
