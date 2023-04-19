#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 200003
#define pb push_back
using namespace std;
typedef pair<int,int> pi;

int n;
int a[maxn];
int b[maxn];
int ans[maxn];
int remA[maxn];
int remB[maxn];
vector<pi> v;
vector<int> others;
map<int,int> hashCntA;
map<int,vector<int> > indicesA;

int main() {
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ ) {
		scanf("%d",&a[i]);
		remA[a[i]]++;
		hashCntA[a[i]]++;
		indicesA[a[i]].pb(i);
	}
	for( int i = 1 ; i <= n ; i++ ) {
		scanf("%d",&b[i]);
		if(remA[b[i]])
			remB[b[i]]++;
		else
			others.pb(b[i]);
	}
	set<pi> s;
	set<pi>::iterator sit;
	map<int,int>::iterator mit;
	for( mit = hashCntA.begin() ; mit != hashCntA.end() ; mit++ ) {
		v.pb( pi( mit->second , mit->first ) );
		if(remB[mit->first])
			s.insert( pi( mit->second , mit->first ) );
	}
	sort(v.begin(),v.end());
	for( int i = 0 ; i < v.size() ; i++ ) {
		int num = v[i].se;
		int times = v[i].fi;
		if(remB[num])
			s.erase(pi(remA[num],num));
		for( int tt = 0 ; tt < times ; tt++ ) {
			int idx = indicesA[num][tt];
			if(s.empty()) {
				if(others.empty()) {
					puts("No");
					return 0;
				}
				int x = others.back();
				others.pop_back();
				ans[idx] = x;
			}
			else {
				sit = s.end();
				sit--;
				int num2 = sit->se;
				int times2 = sit->fi;
				s.erase( pi(times2,num2) );
				remA[num2]--;
				remB[num2]--;
				if(remB[num2])
					s.insert( pi(times2-1,num2) );
				ans[idx] = num2;
			}
		}
		for( int i = 0 ; i < remB[num] ; i++ )
			others.pb(num);
	}
	puts("Yes");
	for( int i = 1 ; i <= n ; i++ )
		printf("%d ",ans[i]);
	puts("");
	return 0;
}
