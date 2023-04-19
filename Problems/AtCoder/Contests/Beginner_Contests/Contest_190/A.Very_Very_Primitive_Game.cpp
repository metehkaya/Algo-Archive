#include <bits/stdc++.h>
using namespace std;

int a,b,c;

int main() {
	scanf("%d%d%d",&a,&b,&c);
	if(a > b)
		puts("Takahashi");
	else if(a < b)
		puts("Aoki");
	else if(c == 0)
		puts("Aoki");
	else
		puts("Takahashi");
	return 0;
}
