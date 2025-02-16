#include <algorithm>
#include <stdio.h>
using namespace std;

const int N = 999;

int main() {
	int n_mult_3 = N/3;
	int n_mult_5 = N/5;
	int n_mult_15 = N/15;
	int sum_mult_3 = 3 * n_mult_3 * (n_mult_3+1) / 2;
	int sum_mult_5 = 5 * n_mult_5 * (n_mult_5+1) / 2;
	int sum_mult_15 = 15 * n_mult_15 * (n_mult_15+1) / 2;
	int ans = sum_mult_3 + sum_mult_5 - sum_mult_15;
	printf("%d\n",ans);
	return 0;
}
