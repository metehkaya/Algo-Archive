#include <bits/stdc++.h>
using namespace std;

int ans;
string s;

int main() {
	cin >> s;
	for( int i = 0 , j = 0 ; i < 3 ; i = j+1 ) {
		j = i;
		while(s[i] == 'R' && j+1 < 3 && s[j+1] == 'R')
			j++;
		if(s[i] == 'R')
			ans = max(ans,j-i+1);
	}
	printf("%d\n",ans);
	return 0;
}
