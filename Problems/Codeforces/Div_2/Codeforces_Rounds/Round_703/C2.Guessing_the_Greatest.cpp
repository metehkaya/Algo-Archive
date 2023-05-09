#include <bits/stdc++.h>
using namespace std;

int n,ans;

int q(int l , int r) {
	int idx;
	printf("? %d %d\n",l,r);
	fflush(stdout);
	scanf("%d",&idx);
	return idx;
}

int main() {
	scanf("%d",&n);
	int idx2 = q(1,n);
	ans = -1;
	if(idx2 > 1 && q(1,idx2) == idx2) {
		int l = 1 , r = idx2-1;
		while(l <= r) {
			int m = (l+r)>>1;
			if(q(m,idx2) == idx2)
				ans = m , l = m+1;
			else
				r = m-1;
		}
	}
	else {
		int l = idx2+1 , r = n;
		while(l <= r) {
			int m = (l+r)>>1;
			if(q(idx2,m) == idx2)
				ans = m , r = m-1;
			else
				l = m+1;
		}
	}
	printf("! %d\n",ans);
	fflush(stdout);
	return 0;
}
