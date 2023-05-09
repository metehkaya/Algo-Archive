#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 100003
#define pb push_back
using namespace std;
typedef pair<int,int> pi;

int n;
set<pi> ans;
int ar[maxn];
vector<int> v[4];

void imp() {
	puts("-1");
	exit(0);
}

int main() {
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ )
		scanf("%d",&ar[i]);
	for( int i = n ; i >= 1 ; i-- ) {
		if(ar[i] == 0);
		else if(ar[i] == 1) {
			v[1].pb(i);
			ans.insert(pi(i,i));
		}
		else if(ar[i] == 2) {
			if(v[1].empty())
				imp();
			else {
				v[2].pb(i);
				int idx = v[1].back();
				v[1].pop_back();
				ans.insert(pi(i,i));
				ans.insert(pi(i,idx));
				ans.erase(pi(idx,idx));
			}
		}
		else {
			bool ok = false;
			for( int k = 3 ; k >= 1 ; k-- )
				if(!v[k].empty()) {
					ok = true;
					int idx = v[k].back();
					v[k].pop_back();
					ans.insert(pi(i,i));
					ans.insert(pi(i,idx));
					v[3].pb(i);
					break;
				}
			if(!ok)
				imp();
		}
	}
	printf("%d\n",ans.size());
	set<pi>::iterator it;
	for( it = ans.begin() ; it != ans.end() ; it++ )
		printf("%d %d\n",it->fi,it->se);
	return 0;
}
