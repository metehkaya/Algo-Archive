#include <bits/stdc++.h>
using namespace std;

int n,x,t;

int main() {
	scanf("%d%d%d",&n,&x,&t);
	int times = (n/x) + ( (n%x > 0) ? 1 : 0 );
	printf("%d\n",times*t);
	return 0;
}
