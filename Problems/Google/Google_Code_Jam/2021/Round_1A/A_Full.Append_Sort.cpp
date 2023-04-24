#include <bits/stdc++.h>
#define maxn 100
using namespace std;

int T,n,ans;
string str[maxn];

bool isAll9(string& s , int l , int r) {
	for( int i = l ; i <= r ; i++ )
		if(s[i] != '9')
			return false;
	return true;
}

void deal(string& s , string& t) {
	int lens = s.length();
	int lent = t.length();
	if(lens > lent)
		return;
	else if(lens == lent) {
		if(s > t)
			return;
		ans++;
		s.push_back('0');
	}
	else {
		int ord = 0;
		for( int i = 0 ; i < lens ; i++ )
			if(s[i] > t[i]) {
				ord = 1;
				break;
			}
			else if(s[i] < t[i]) {
				ord = -1;
				break;
			}
		if(ord == 1) {
			int add = lent - lens;
			ans += add;
			for( int i = 0 ; i < add ; i++ )
				s.push_back('0');
		}
		else if(ord == -1) {
			int add = lent - lens + 1;
			ans += add;
			for( int i = 0 ; i < add ; i++ )
				s.push_back('0');
		}
		else {
			if(isAll9(t,lens,lent-1)) {
				int add = lent - lens + 1;
				ans += add;
				for( int i = 0 ; i < add ; i++ )
					s.push_back('0');
			}
			else {
				s = t;
				ans += lent - lens;
				for( int i = lent-1 ; i >= lens ; i-- )
					if(s[i] != '9') {
						s[i]++;
						break;
					}
					else
						s[i] = '0';
			}
		}
	}
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d",&n);
		for( int i = 0 ; i < n ; i++ )
			cin >> str[i];
		ans = 0;
		for( int i = 1 ; i < n ; i++ )
			deal(str[i],str[i-1]);
		printf("Case #%d: %d\n",tc,ans);
	}
	return 0;
}
