#include <algorithm>
#include <stdio.h>
using namespace std;

const int N = 100;

int main() {
	int sum1 = N*(N+1)*(2*N+1)/6;
	int sum2 = N*(N+1)/2;
	int ans = sum2*sum2 - sum1;
	printf("%d\n",ans);
	return 0;
}
