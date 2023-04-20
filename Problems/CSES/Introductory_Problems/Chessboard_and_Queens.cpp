#include <bits/stdc++.h>
using namespace std;

string s[8];

int solve(int row , int bm1 , int bm2 , int bm3) {
	if(row == 8)
		return 1;
	int ans = 0;
	for( int i = 0 ; i < 8 ; i++ )
		if(s[row][i] == '.') {
			int a = (1 << i);
			int b = (1 << (row+i));
			int c = (1 << (row-i+7));
			if((bm1&a) || (bm2&b) || (bm3&c))
				continue;
			ans += solve(row+1,bm1|a,bm2|b,bm3|c);
		}
	return ans;
}

int main() {
	for( int i = 0 ; i < 8 ; i++ )
		cin >> s[i];
	cout << solve(0,0,0,0) << endl;
	return 0;
}