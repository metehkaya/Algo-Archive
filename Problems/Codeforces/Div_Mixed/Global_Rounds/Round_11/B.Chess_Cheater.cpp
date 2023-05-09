#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int T,n,k;
string s;

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		cin >> n >> k >> s;
		vector<int> v;
		bool seenW = false;
		int score = 0 , totalW = 0 , cntL = 0;
		for( int i = 0 ; i < n ; i++ ) {
			if(s[i] == 'L') {
				if(seenW) {
					if(++cntL == 1)
						v.pb(1);
					else
						v[v.size()-1]++;
				}
			}
			else {
				cntL = 0;
				totalW++;
				seenW = true;
				if(i == 0 || s[i-1] == 'L')
					score++;
				else
					score += 2;
			}
		}
		if(!v.empty() && s[n-1] == 'L')
			v.pop_back();
		sort(v.begin(),v.end());
		for( int i = 0 ; k && i < v.size() ; i++ ) {
			int mn = min(v[i],k);
			k -= mn;
			totalW += mn;
			score += 2*mn;
			if(mn == v[i])
				score++;
		}
		k = min(n-totalW,k);
		if(k) {
			if(score == 0)
				score = 2*k-1;
			else
				score += 2*k;
		}
		printf("%d\n",score);
	}
	return 0;
}
