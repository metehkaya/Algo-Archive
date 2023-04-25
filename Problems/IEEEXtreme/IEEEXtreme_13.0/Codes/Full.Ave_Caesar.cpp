#include <bits/stdc++.h>
#define maxn 1000003
#define pb push_back
using namespace std;

int T,n,k;
char s[maxn];

vector<int> v;
vector<string> strs;

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		v.clear();
		strs.clear();
		scanf("%s",s);
		n = strlen(s);
		v.pb(0);
		for( int i = 1 ; i < n ; i++ )
			if( s[i] < s[i-1] )
				v.pb(i);
		v.pb(n);
		k = (int) v.size() - 1;
		for( int i = 0 ; i < k ; i++ ) {
			string str = "";
			for( int j = v[i] ; j < v[i+1] ; j++ )
				str += s[j];
			strs.pb(str);
		}
		bool ok = true;
		for( int i = 0 ; ok && i < k-1 ; i++ )
			if( strs[i].compare(strs[i+1]) > 0 )
				ok = false;
		printf("%c", '0'+ok);
	}
	return 0;
}
