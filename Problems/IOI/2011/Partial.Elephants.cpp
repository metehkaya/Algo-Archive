#include <bits/stdc++.h>
#include "elephants.h"
#define maxn 100
using namespace std;

int n,k;
int ar[maxn];
int arr[maxn];

void init(int N, int K, int x[]) {
	n = N;
	k = K;
	for( int i = 0 ; i < n ; i++ )
		ar[i] = x[i];
}

int update(int i, int y) {
	ar[i] = y;
	for( int i = 0 ; i < n ; i++ )
		arr[i] = ar[i];
	sort(arr,arr+n);
	int ans = 0;
	int last = INT_MIN;
	for( int i = 0 ; i < n ; i++ )
		if(arr[i] > last+k)
			ans++ , last = arr[i];
	return ans;
}
