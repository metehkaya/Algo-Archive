#include <bits/stdc++.h>
using namespace std;

class PoisonedSwamp {
	public:
	int n,m;
	bool mark[23][23][10];
	vector<string> ar;
	int dir[4] = {0,1,0,-1};
	bool f(int r , int c , int k) {
		mark[r][c][k] = true;
		if(r == n-1 && c == m-1)
			return true;
		for( int i = 0 ; i < 4 ; i++ ) {
			int x = r + dir[i];
			int y = c + dir[i^1];
			if(x < 0 || x >= n || y < 0 || y >= m)
				continue;
			if(ar[x][y] == '#')
				continue;
			int k2 = k;
			if(ar[x][y] == 'S')
				k2 = 0;
			else if(ar[x][y] >= '1' && ar[x][y] <= '9')
				k2 += ar[x][y]-'0';
			if(k2 >= 10)
				continue;
			if(mark[x][y][k2])
				continue;
			if(f(x,y,k2))
				return true;
		}
		return false;
	}
    string cross(vector<string> swamp) {
		ar = swamp;
    	n = swamp.size();
    	m = swamp[0].length();
    	if(f(0,0,0))
    		return "possible";
    	return "impossible";
	}
};
