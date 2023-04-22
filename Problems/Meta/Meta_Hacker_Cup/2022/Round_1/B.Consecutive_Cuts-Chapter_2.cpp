#include <bits/stdc++.h>
#define maxn 500003
#define pb push_back
using namespace std;

int T,N,n,k;
int a[maxn];
int b[2*maxn];
int lps[maxn];
string ans;
vector<int> indices;

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

void reset() {
	indices.clear();
}

void input() {
	scanf("%d%d",&n,&k);
	for( int i = 0 ; i < n ; i++ )
		scanf("%d",&a[i]);
	for( int i = 0 ; i < n ; i++ )
		scanf("%d",&b[i]);
}

void computeLPS() {
	int len = 0;
	lps[0] = 0;
	int i = 1;
	while(i < n) {
		if(a[i] == a[len])
			lps[i++] = ++len;
		else {
			if(len)
				len = lps[len-1];
			else
				lps[i++] = 0;
		}
	}
}

void searchKMP() {
	int i = 0 , j = 0;
	while(N-i >= n-j) {
		if(a[j] == b[i])
			i++,j++;
		if(j == n) {
			indices.pb(i-j);
			j = lps[j-1];
		}
		else if(i < N && a[j] != b[i]) {
			if(j)
				j = lps[j-1];
			else
				i = i+1;
		}
	}
}

void solve() {
	bool diff = false;
	for( int i = 1 ; i < n ; i++ )
		if(a[i] != a[0])
			diff = true;
	if(!diff) {
		ans = "YES";
		return;
	}
	if(n == 2) {
		if(a[0] == b[0] && a[1] == b[1] && k%2 == 0)
			ans = "YES";
		else if(a[0] == b[1] && a[1] == b[0] && k%2 == 1)
			ans = "YES";
		else
			ans = "NO";
	}
	else {
		N = 2*n-1;
		for( int i = n ; i < N ; i++ )
			b[i] = b[i-n];
		computeLPS();
		searchKMP();
		if(indices.empty())
			ans = "NO";
		else {
			if(k == 0) {
				if(indices[0] == 0)
					ans = "YES";
				else
					ans = "NO";
			}
			else if(k == 1 && (int)indices.size() == 1 && indices[0] == 0)
				ans = "NO";
			else
				ans = "YES";
		}
	}
}

int main() {
	io();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		input();
		solve();
		printf("Case #%d: %s\n",tc,ans.c_str());
	}
	return 0;
}
