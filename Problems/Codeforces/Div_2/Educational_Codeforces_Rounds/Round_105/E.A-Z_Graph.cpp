#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;

int n,m,k;
int cnt,same;
map<pi,string> mp;

int main() {
	scanf("%d%d",&n,&m);
	for( int q = 0 ; q < m ; q++ ) {
		int u,v,k;
		string s,w , ans = "NO";
		cin >> s;
		if(s == "+") {
			cin >> u >> v >> w;
			mp[pi(u,v)] = w;
			pi p = pi(v,u);
			if(mp.find(p) != mp.end()) {
				cnt++;
				if(mp[p] == w)
					same++;
			}
		}
		else if(s == "-") {
			cin >> u >> v;
			w = mp[pi(u,v)];
			pi p = pi(v,u);
			mp.erase(pi(u,v));
			if(mp.find(p) != mp.end()) {
				cnt--;
				if(mp[p] == w)
					same--;
			}
		}
		else {
			cin >> k;
			if(k % 2 == 1 && cnt)
				ans = "YES";
			else if(k % 2 == 0 && same)
				ans = "YES";
			cout << ans << endl;
		}
	}
	return 0;
}
