#include <bits/stdc++.h>
using namespace std;

double X1,Y1,X2,Y2;

int main() {
	cin >> X1 >> Y1 >> X2 >> Y2;
	double rate = (X2-X1) / (Y1+Y2);
	double ans = X1+Y1*rate;
	printf("%.7lf\n",ans);
	return 0;
}
