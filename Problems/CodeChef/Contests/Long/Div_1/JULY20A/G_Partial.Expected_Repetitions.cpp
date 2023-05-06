#include <bits/stdc++.h>
#define maxc 26
#define maxn 2001
#define mod 998244353
using namespace std;
typedef long long LL;

struct Node {
	int id;
	vector<Node*> child;
	Node() {
		id = -1;
		child.resize(maxc,NULL);
	}
}*root;

int T,n,ans;
int a[maxc];
int sum[maxn];
int cntIdx[maxn];
int val[maxn][maxn];
int seen[maxn][maxn];
string s;

LL calcPow(int x , int y) {
	if(y == 0)
		return 1;
	LL res = calcPow(x,y/2);
	res = res*res % mod;
	if(y & 1)
		res = res*x % mod;
	return res;
}

int main() {
	root = new Node();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		cin >> s;
		for( int i = 0 ; i < maxc ; i++ )
			scanf("%d",&a[i]);
		n = s.length();
		for( int i = 1 ; i <= n ; i++ )
			sum[i] = ( sum[i-1] + a[s[i-1]-'a'] ) % mod;
		for( int i = 0 ; i < n ; i++ ) {
			int len = 0;
			Node* node = root;
			for( int j = i ; j < n ; j++ ) {
				len++;
				int c = s[j]-'a';
				if(node->child[c] == NULL) {
					node->child[c] = new Node();
					node = node->child[c];
					node->id = ++cntIdx[len];
				}
				else
					node = node->child[c];
				val[len][i] = node->id;
			}
		}
		ans = 0;
		for( int len = 1 ; len <= n ; len++ ) {
			for( int i = 0 ; i <= n-len ; i++ )
				if(seen[len][i] != tc) {
					int w = (sum[i+len] - sum[i] + mod) % mod;
					int j = i , cnt = 0;
					while(j+len <= n && val[len][i] == val[len][j]) {
						cnt++;
						seen[len][j] = true;
						j += len;
					}
					int l = 1 , r = min(len-1,n-j) , last = j;
					while(l <= r) {
						int m = (l+r) >> 1;
						if(val[m][i] == val[m][j])
							last = j+m , l = m+1;
						else
							r = m-1;
					}
					for( int k = i ; k < j ; k += len ) {
						seen[len][k] = tc;
						int times = last-k+1-len;
						int add = (LL) times * w % mod;
						ans = (ans + add) % mod;
					}
				}
		}
		ans = 2*ans % mod;
		ans = calcPow(n,mod-2) * ans % mod;
		ans = calcPow(n+1,mod-2) * ans % mod;
		printf("%d\n",ans);
	}
	return 0;
}
