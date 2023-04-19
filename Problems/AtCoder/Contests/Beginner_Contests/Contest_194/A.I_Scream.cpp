#include <bits/stdc++.h>
using namespace std;

int a,b;

int main() {
	scanf("%d%d",&a,&b);
	a += b;
	if(a >= 15 && b >= 8)
		puts("1");
	else if(a >= 10 && b >= 3)
		puts("2");
	else if(a >= 3)
		puts("3");
	else
		puts("4");
	return 0;
}
