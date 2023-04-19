#include <bits/stdc++.h>
#define maxn 100000
using namespace std;

int n,sum;
int a[maxn];

int main() {
	scanf("%d",&n);
	for( int i = 0 ; i < n ; i++ )
		scanf("%d",&a[i]);
	for( int i = 0 , x ; i < n ; i++ ) {
		scanf("%d",&x);
		sum += x*a[i];
	}
	string str = (sum == 0) ? "Yes" : "No";
	cout << str << endl;
	return 0;
}
