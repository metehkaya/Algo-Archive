#include <bits/stdc++.h>
#define maxn 200000
using namespace std;

int n,m,k,ans;
int a[maxn];
int b[maxn];

int main() {
	scanf("%d%d%d",&n,&m,&k);
	for( int i = 0 ; i < n ; i++ )
		scanf("%d",&a[i]);
	for( int i = 0 ; i < m ; i++ )
		scanf("%d",&b[i]);
	sort(a,a+n);
	sort(b,b+m);
	int i = 0 , j = 0;
	while(i < n && j < m) {
		if(a[i] < b[j] && b[j] - a[i] > k)
			i++;
		else if(b[j] < a[i] && a[i] - b[j] > k)
			j++;
		else
			i++,j++,ans++;
	}
	printf("%d\n",ans);
	return 0;
}