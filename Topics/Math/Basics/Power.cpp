#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef long long LL;

int f(int x , int y) {
	if(y == 0)
		return 1;
	LL res = f(x,y/2);
	res = (res*res) % mod;
	if(y & 1)
		res = (res*x) % mod;
	return res;
}

int main() {
	int x,y;
	scanf("%d%d",&x,&y);
	printf("%d\n",f(x,y));
	return 0;
}
