#include <bits/stdc++.h>
using namespace std;

int ar[7];

int main() {
	for( int i = 0 ; i < 7 ; i++ )
		scanf("%d",&ar[i]);
	sort(ar,ar+7);
	int a = ar[0];
	int b = ar[1];
	int c = (ar[0] + ar[1] == ar[2]) ? ar[3] : ar[2];
	printf("%d %d %d\n",a,b,c);
	return 0;
}
