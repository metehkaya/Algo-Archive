#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL ans;
int n,x;
int ar[40];
map<int,int> cnt;

void f(int id , int stop , int sum , int goo) {
	if(sum > x)
		return;
	if(id == stop) {
		if(goo == 1)
			cnt[sum]++;
		else {
			auto it = cnt.find(x-sum);
			if(it != cnt.end())
				ans += it->second;
		}
		return;
	}
	f(id+goo,stop,sum,goo);
	f(id+goo,stop,sum+ar[id],goo);
}

int main() {
	scanf("%d%d",&n,&x);
	for( int i = 0 ; i < n ; i++ )
		scanf("%d",&ar[i]);
	int take = n/2;
	f(0,take,0,1);
	f(n-1,take-1,0,-1);
	printf("%lld\n",ans);
	return 0;
}