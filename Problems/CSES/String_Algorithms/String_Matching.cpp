#include <bits/stdc++.h>
#define maxn 1000001
using namespace std;

int n,m;
string s,t;
int lps[maxn];

void computeLPS() {
	int i = 1 , len = 0;
	while(i < m) {
		if(t[i] == t[len])
			lps[i++] = ++len;
		else if(len != 0)
			len = lps[len-1];
		else
			lps[i++] = 0;
	}
}

int kmp() {
	int i = 0 , j = 0 , res = 0;
	while(i < n) {
		if(s[i] == t[j]) {
			i++ , j++;
			if(j == m)
				res++ , j = lps[j-1];
		}
		else if(j != 0)
			j = lps[j-1];
		else
			i = i+1;
	}
	return res;
}

int main() {
	cin >> s >> t;
	n = s.length();
	m = t.length();
	computeLPS();
	printf("%d\n",kmp());
	return 0;
}