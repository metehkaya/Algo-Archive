#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 100003
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> pi;

int n;
LL sum;
int ar[maxn];
int arr[maxn];
vector<pi> vec;

int main() {
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ ) {
		scanf("%d",&ar[i]);
		vec.pb(pi(ar[i],i));
	}
	sort(vec.begin(),vec.end());
	for( int i = 0 ; i < n ; i++ ) {
		int val = vec[i].fi;
		int ind = vec[i].se;
		arr[ind] = 1;
		if(ind > 1 && ar[ind] > ar[ind-1])
			arr[ind] = max(arr[ind],arr[ind-1]+1);
		if(ind < n && ar[ind] > ar[ind+1])
			arr[ind] = max(arr[ind],arr[ind+1]+1);
		sum += arr[ind];
	}
	printf("%lld\n",sum);
	return 0;
}
