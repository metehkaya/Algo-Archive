#include <bits/stdc++.h>
using namespace std;

int s;

int main() {
	scanf("%d",&s);
	if(s <= 90)
		puts("0 No punishment");
	else if(s <= 110)
		printf("%d Warning\n",300*(s-90));
	else
		printf("%d License removed\n",500*(s-90));
	return 0;
}
