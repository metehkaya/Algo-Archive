#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int n,k;

int main() {
	scanf("%d%d",&n,&k);
	while(k--) {
		vector<int> nums;
		while(n) {
			nums.pb(n%10);
			n /= 10;
		}
		sort(nums.begin(),nums.end());
		int d = nums.size() , x = 0 , y = 0;
		for( int i = 0 ; i < d ; i++ )
			x = 10*x + nums[i];
		for( int i = d-1 ; i >= 0 ; i-- )
			y = 10*y + nums[i];
		n = y-x;
	}
	printf("%d\n",n);
	return 0;
}
