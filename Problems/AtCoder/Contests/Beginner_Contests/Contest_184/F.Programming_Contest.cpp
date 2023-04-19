#include <bits/stdc++.h>
#define maxn 40
using namespace std;
typedef long long LL;

int n;
LL x,ans;
LL ar[maxn];
set<LL> s;

void g(int id , int son , LL sum) {
	if(id == son) {
		s.insert(sum);
		return;
	}
	g(id+1,son,sum);
	g(id+1,son,sum+ar[id]);
}

void f(int id , int son , LL sum) {
	if(sum > x)
		return;
	if(id == son) {
		if(n <= 20)
			ans = max(ans,sum);
		else {
			LL rem = x-sum;
			set<LL>::iterator it = s.upper_bound(rem);
			it--;
			ans = max(ans,sum+(*it));
		}
		return;
	}
	f(id+1,son,sum);
	f(id+1,son,sum+ar[id]);
}

int main() {
	cin >> n >> x;
	for( int i = 0 ; i < n ; i++ )
		cin >> ar[i];
	if(n > 20) {
		g(20,n,0);
		f(0,20,0);
	}
	else
		f(0,n,0);
	cout << ans << endl;
	return 0;
}
