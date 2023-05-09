#include <bits/stdc++.h>
#define maxn 5003
#define pb push_back
using namespace std;

int n;
int ar[maxn];
int mn[maxn][maxn];

int f(int l , int r , int dec) {
	int len = r-l+1;
	int minVal = mn[l][r];
	int diff = minVal - dec;
	int ans = diff;
	vector<int> v;
	for( int i = l ; i <= r ; i++ )
		if(ar[i] > minVal)
			v.pb(i);
	int k = v.size();
	for( int i = 0 , j ; i < k ; i = j+1 ) {
		j = i;
		while(j+1 < k && v[j+1]-v[j] == 1)
			j++;
		ans += f(v[i],v[j],minVal);
	}
	ans = min(ans,len);
	return ans;
}

int main() {
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i++ )
		scanf("%d",&ar[i]);
	for( int i = 1 ; i <= n ; i++ ) {
		mn[i][i] = ar[i];
		for( int j = i+1 ; j <= n ; j++ )
			mn[i][j] = min( mn[i][j-1] , ar[j] );
	}
	printf("%d\n",f(1,n,0));
	return 0;
}
