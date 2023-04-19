#include <bits/stdc++.h>
using namespace std;

int v,t,s,d;

int main() {
	scanf("%d%d%d%d",&v,&t,&s,&d);
	if(v*t <= d && d <= v*s)
		puts("No");
	else
		puts("Yes");
	return 0;
}
