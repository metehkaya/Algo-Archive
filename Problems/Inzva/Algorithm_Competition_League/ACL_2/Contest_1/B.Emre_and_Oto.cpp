#include <bits/stdc++.h>
using namespace std;

int ar[3];

int main() {
	for( int i = 0 ; i < 3 ; i++ )
		scanf("%d",&ar[i]);
	sort(ar,ar+3);
	printf("%d\n",max(ar[1]-ar[0]-1,ar[2]-ar[1]-1));
	return 0;
}