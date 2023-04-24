#include <bits/stdc++.h>
#define maxb 64
#define maxn 50002
using namespace std;

int T,n;
string s;
bool isPal5[maxb];
bool isPal6[maxb];
bool mark[maxn][maxb];

void reset() {
	memset(mark,false,sizeof(mark));
}

bool solve(int id , int bmask) {
	if(id >= 5 && isPal5[bmask])
		return false;
	if(id >= 6 && isPal6[bmask])
		return false;
	if(id == n)
		return true;
	if(mark[id][bmask])
		return false;
	mark[id][bmask] = true;
	if(bmask >= maxb/2)
		bmask -= maxb/2;
	bmask *= 2;
	if(s[id] != '?') {
		int c = s[id]-'0';
		if(solve(id+1,bmask+c))
			return true;
	}
	else {
		if(solve(id+1,bmask) || solve(id+1,bmask+1))
			return true;
	}
	return false;
}

bool checkPal(vector<int>& v_bits , int s , int e) {
	for( int i = s ; i <= e ; i++ )
		if(v_bits[i] != v_bits[s+e-i])
			return false;
	return true;
}

void precalc() {
	vector<int> v_bits(6,0);
	for( int bmask = 0 ; bmask < maxb ; bmask++ ) {
		for( int i = 0 ; i < 6 ; i++ )
			v_bits[i] = ((bmask & (1<<i)) > 0);
		isPal5[bmask] = checkPal(v_bits,0,4);
		isPal6[bmask] = checkPal(v_bits,0,5);
	}
}

int main() {
	precalc();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		cin >> n >> s;
		string ans = (solve(0,0) ? "POSSIBLE" : "IMPOSSIBLE");
		printf("Case #%d: %s\n",tc,ans.c_str());
	}
	return 0;
}
