#include <bits/stdc++.h>
using namespace std;

int n,m,t,ans;

int main() {
    scanf("%d%d%d",&n,&m,&t);
	int l = 1 , r = m;
	while(t--) {
	    int x;
	    scanf("%d",&x);
	    if(l <= x and x <= r)
	        continue;
        else if(x < l) {
            ans += l-x;
            l = x;
            r = l+m-1;
        }
        else {
            ans += x-r;
            r = x;
            l = r-m+1;
        }
	}
    printf("%d\n",ans);
	return 0;
}