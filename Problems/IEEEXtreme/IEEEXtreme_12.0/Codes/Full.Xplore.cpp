#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 10000
#define maxN 2000002
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<string,int> psi;

int N,n;
string str[maxn];
string names[maxN];

vector<psi> ans;
vector<LL> v[maxN];
map<string,int> myhash;

bool comp( psi a , psi b ) {
	if( a.se != b.se )
		return a.se > b.se;
	return a.fi < b.fi;
}

int main() {
	scanf( "%d" , &n );
	getline( cin , str[0] );
	for( int i = 0 ; i < n ; i++ )
		getline( cin , str[i] );
	for( int i = 0 ; i < n ; i++ ) {
		int len = str[i].length();
		int j2 = len - 21;
		while( str[i].substr( j2 , 21 ) != "\"citing_paper_count\":" )
			j2--;
		int j1 = j2 + 21;
		while( str[i][j1] < '0' || str[i][j1] > '9' )
			j1++;
		LL sum = 0;
		while( str[i][j1] >= '0' && str[i][j1] <= '9' ) {
			sum *= 10;
			sum += str[i][j1] - '0';
			j1++;
		}
		for( int j = 0 ; j < len - 12 ; j++ ) {
			if( str[i].substr( j , 12 ) == "\"full_name\":" ) {
				string name = "";
				int l = j + 12;
				while( !( str[i][l] >= 'a' && str[i][l] <= 'z' ) && !( str[i][l] >= 'A' && str[i][l] <= 'Z' ) )
					l++;
				while( str[i][l] != '\"' ) {
					name = name + str[i][l];
					l++;
				}
				int val = myhash[name];
				if( !val ) {
					val = myhash[name] = ++N;
					names[val] = name;
				}
				v[val].pb( sum );
			}
		}
	}
	for( int i = 1 ; i <= N ; i++ ) {
		sort( v[i].begin() , v[i].end() );
		int cnt = 0 , sz = v[i].size();
		while( cnt + 1 <= v[i].size() && v[i][sz-cnt-1] >= cnt + 1 )
			cnt++;
		ans.pb( psi( names[i] , cnt ) );
	}
	sort( ans.begin() , ans.end() , comp );
	for( int i = 0 ; i < N ; i++ )
		cout << ans[i].fi << " " << ans[i].se << endl;
	return 0;
}