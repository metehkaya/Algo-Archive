#include <bits/stdc++.h>
#define maxn 500003
using namespace std;
typedef long long LL;

int n;
string s;
LL ans,sum;
int cnt[maxn];

int main() {
	cin >> n >> s;
	for( int i = 0 , curr = 0 ; i < n ; i++ ) {
		if(s[i] == '0')
			cnt[curr = 0]++;
		else {
			if(++curr == 1) {
				sum += cnt[0]+1;
				cnt[1] += cnt[0]+1;
				cnt[0] = 0;
			}
			else {
				int rem = cnt[curr-1]-1;
				sum += rem+curr;
				cnt[curr] += rem+1;
				cnt[curr-1] = 1;
			}
		}
		ans += sum;
	}
	printf("%lld\n",ans);
	return 0;
}
