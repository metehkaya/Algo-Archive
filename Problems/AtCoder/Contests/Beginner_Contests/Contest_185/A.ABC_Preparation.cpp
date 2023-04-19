#include <bits/stdc++.h>
using namespace std;

int a,b,c,d;

int main() {
	scanf("%d%d%d%d",&a,&b,&c,&d);
	printf("%d\n",min(min(a,b),min(c,d)));
	return 0;
}
