#include <bits/stdc++.h>
#define maxn 100000
using namespace std;

int n;
double ar[maxn][2];

double getarea() {
	double sum = 0;
	for( int i = 0 ; i < n ; i++ ) {
		double x1 = ar[i][0];
		double y1 = ar[i][1];
		double x2 = ar[(i+1)%n][0];
		double y2 = ar[(i+1)%n][1];
		sum += x1*y2-x2*y1;
	}
	if(sum < 0)
		sum = -sum;
	return sum / 2.0;
}

int main() {
	scanf("%d",&n);
	for( int i = 0 ; i < n ; i++ )
		scanf("%lf%lf",&ar[i][0],&ar[i][1]);
	double area = getarea();
	printf("%lf\n",area);
	return 0;
}
