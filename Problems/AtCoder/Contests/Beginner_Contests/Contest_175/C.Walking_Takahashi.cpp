#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL x,k,d;

int main() {
	cin >> x >> k >> d;
	x = max(x,-x);
	LL divv = x/d;
	if(divv >= k)
		cout << x-k*d;
	else {
		LL rem = x%d;
		if(divv%2 == k%2)
			cout << rem;
		else
			cout << d-rem;
	}
	return 0;
}
