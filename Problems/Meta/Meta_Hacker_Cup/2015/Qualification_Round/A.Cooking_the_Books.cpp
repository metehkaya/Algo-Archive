#include <bits/stdc++.h>
using namespace std;

int T,n;
string s;

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

int main() {
	io();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		cin >> s;
		n = s.length();
		string ansmn=s,ansmx=s;
		for( int i = 0 ; i < n-1 ; i++ ) {
			int idx = -1;
			for( int j = n-1 ; j > i ; j-- )
				if(i || s[j] != '0')
					if(idx == -1 || s[j] < s[idx])
						idx = j;
			if(idx != -1 && s[idx] < s[i]) {
				swap(ansmn[i],ansmn[idx]);
				break;
			}
		}
		for( int i = 0 ; i < n-1 ; i++ ) {
			int idx = -1;
			for( int j = n-1 ; j > i ; j-- )
				if(i || s[j] != '0')
					if(idx == -1 || s[j] > s[idx])
						idx = j;
			if(idx != -1 && s[idx] > s[i]) {
				swap(ansmx[i],ansmx[idx]);
				break;
			}
		}
		printf("Case #%d: %s %s\n",tc,ansmn.c_str(),ansmx.c_str());
	}
	return 0;
}
