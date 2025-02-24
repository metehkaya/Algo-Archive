#include <bits/stdc++.h>
using namespace std;

int n,k;

int main() {
	scanf("%d",&k);
	while(n*(n+1)/2+1 < k)
	    n++;
	printf("%d\n",n);
	return 0;
}