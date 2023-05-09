#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int T,n;
string s;

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		cin >> n >> s;
		vector<int> v;
		for( int i = 0 , j = 0 ; i < n ; i = j ) {
			while(j < n && s[i] == s[j])
				j++;
			v.pb(j-i);
		}
		int ans = 0;
		n = v.size();
		for( int i = 0 , j = 0 ; i < n ; i++ ) {
			while(j < n && v[j] <= 1)
				j++;
			if(j < n)
				v[j]--;
			else
				v[i++] = 0;
			if(i < n)
				v[i] = 0;
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
