#include <bits/stdc++.h>
#define maxn 100
using namespace std;

int n,ans;
int ar[maxn];

int main() {
	scanf("%d",&n);
	for( int i = 0 ; i < n ; i++ )
		scanf("%d",&ar[i]);
	for( int i = 0 ; i < n ; i++ ) {
		set<int> s;
		int sum = 0;
		for( int j = i , k = 1 ; j < n ; j++ , k++ ) {
			sum += ar[j];
			s.insert(ar[j]);
			if(sum % k == 0 && s.find(sum/k) != s.end())
				ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
