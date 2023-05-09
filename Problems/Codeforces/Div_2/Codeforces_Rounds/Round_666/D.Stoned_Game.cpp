#include <bits/stdc++.h>
#define maxn 101
using namespace std;

int T,n;
string ans;
int ar[maxn];

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d",&n);
		for( int i = 1 ; i <= n ; i++ )
			scanf("%d",&ar[i]);
		sort(ar+1,ar+n+1);
		ans = "HL";
		int prev = -1;
		while(true) {
			int id = 0;
			for( int i = 1 ; i <= n ; i++ )
				if(i != prev && ar[i] > ar[id])
					id = i;
			if(id == 0)
				break;
			prev = id;
			ar[id]--;
			if(ans == "T")
				ans = "HL";
			else
				ans = "T";
		}
		cout << ans << endl;
	}
	return 0;
}
