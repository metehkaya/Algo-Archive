#include <bits/stdc++.h>
#define maxn 100001
using namespace std;
typedef long long LL;

int n,m;
LL costx,costy;
LL sumx[maxn];
LL sumy[maxn];
vector<int> x,y;

int main() {
	scanf("%d%d",&n,&m);
	for( int i = 0 , valx , valy ; i < n ; i++ ) {
	    scanf("%d%d",&valx,&valy);
	    x.push_back(valx);
	    y.push_back(valy);
	    costx += abs(valx);
	    costy += abs(valy);
	}
	string str;
	cin >> str;
	sort(x.begin(),x.end());
	sort(y.begin(),y.end());
	LL currx = 0 , curry = 0;
	for(char c : str) {
	    if(c == 'I') {
	        int idx = upper_bound(x.begin(),x.end(),currx) - x.begin();
	        costx += idx - (n-idx);
	        currx++;
	    }
	    else if(c == 'Z') {
	        int idx = lower_bound(x.begin(),x.end(),currx) - x.begin();
	        costx -= idx - (n-idx);
	        currx--;
	    }
	    else if(c == 'S') {
	        int idx = upper_bound(y.begin(),y.end(),curry) - y.begin();
	        costy += idx - (n-idx);
	        curry++;
	    }
	    else {
	        int idx = lower_bound(y.begin(),y.end(),curry) - y.begin();
	        costy -= idx - (n-idx);
	        curry--;
	    }
	    printf("%lld\n",costx+costy);
	}
	return 0;
}