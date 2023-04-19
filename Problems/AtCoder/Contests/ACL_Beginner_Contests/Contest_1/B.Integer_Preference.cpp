#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL a,b,c,d;

int main() {
	cin >> a >> b >> c >> d;
	if(max(a,c) <= min(b,d))
		puts("Yes");
	else
		puts("No");
	return 0;
}
