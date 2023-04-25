#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL n,m;

LL getScore(LL i) {
	return 2*i + min(n-3*i,(m-3*i)/2);
}

LL f(LL x , LL y) {
	if(y-x<=2) {
		LL score = 0;
		for( LL i = x ; i <= y ; i++ )
			score = max(score, getScore(i));
		return score;
	}
	LL scoreX = getScore(x);
	LL scoreY = getScore(y);
	LL jump = (y-x)/3;
	if(scoreX < scoreY)
		return f(x+jump,y);
	else
		return f(x,y-jump);
}

int main() {
	scanf("%lld%lld",&n,&m);
	if(n>m)
		swap(n,m);
	m = min(m,2*n);
	printf("%lld\n",f(0,n/3));
	return 0;
}
