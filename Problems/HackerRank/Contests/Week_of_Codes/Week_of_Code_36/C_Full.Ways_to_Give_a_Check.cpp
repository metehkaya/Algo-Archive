#include <bits/stdc++.h>
using namespace std;

int T,ans;
int op_kx,op_ky;
int my_kx,my_ky;
char s[12][12];
int dir[8][2] = {{1,2},{2,1},{1,-2},{2,-1},{-1,2},{-2,1},{-1,-2},{-2,-1}};

int checkN(int r , int c , int kx , int ky) {
	for( int i = 0 ; i < 8 ; i++ ) {
		int cx = r + dir[i][0];
		int cy = c + dir[i][1];
		if(cx == kx && cy == ky)
			return 1;
	}
	return 0;
}

int checkRup(int r , int c , int kx , int ky) {
	if(c != ky || kx >= r)
		return 0;
	for( int i = r - 1 ; i > kx ; i-- )
		if(s[i][c] != '#')
			return 0;
	return 1;
}

int checkRdown(int r , int c , int kx , int ky) {
	if(c != ky || kx <= r)
		return 0;
	for( int i = r + 1 ; i < kx ; i++ )
		if(s[i][c] != '#')
			return 0;
	return 1;
}

int checkRleft(int r , int c , int kx , int ky) {
	if(r != kx || ky >= c)
		return 0;
	for( int j = c - 1 ; j > ky ; j-- )
		if(s[r][j] != '#')
			return 0;
	return 1;
}

int checkRright(int r , int c , int kx , int ky) {
	if(r != kx || ky <= c)
		return 0;
	for( int j = c + 1 ; j < ky ; j++ )
		if(s[r][j] != '#')
			return 0;
	return 1;
}

int checkR(int r , int c , int kx , int ky) {
	return min( 1 , checkRup( r , c , kx , ky ) + checkRdown( r , c , kx , ky ) + checkRleft( r , c , kx , ky ) + checkRright( r , c , kx , ky ) );
}

int checkBupleft(int r , int c , int kx , int ky) {
	if(r-c != kx-ky || kx >= r)
		return 0;
	for( int i = r - 1 , j = c - 1 ; i > kx ; i-- , j-- )
		if(s[i][j] != '#')
			return 0;
	return 1;
}

int checkBdownright(int r , int c , int kx , int ky) {
	if(r-c != kx-ky || kx <= r)
		return 0;
	for( int i = r + 1 , j = c + 1 ; i < kx ; i++ , j++ )
		if(s[i][j] != '#')
			return 0;
	return 1;
}

int checkBupright(int r , int c , int kx , int ky) {
	if(r+c != kx+ky || kx >= r)
		return 0;
	for( int i = r - 1 , j = c + 1 ; i > kx ; i-- , j++ )
		if(s[i][j] != '#')
			return 0;
	return 1;
}

int checkBdownleft(int r , int c , int kx , int ky) {
	if(r+c != kx+ky || kx <= r)
		return 0;
	for( int i = r + 1 , j = c - 1 ; i < kx ; i++ , j-- )
		if(s[i][j] != '#')
			return 0;
	return 1;
}

int checkB(int r , int c , int kx , int ky) {
	return min(1,checkBupleft(r,c,kx,ky)+checkBdownright(r,c,kx,ky)+checkBupright(r,c,kx,ky)+checkBdownleft(r,c,kx,ky));
}

int checkQ(int r , int c , int kx , int ky) {
	return min(1,checkR(r,c,kx,ky)+checkB(r,c,kx,ky));
}

int checkInvalid(int kx , int ky) {
	for( int i = 1 ; i <= 8 ; i++ )
		for( int j = 1 ; j <= 8 ; j++ ) {
			if(s[i][j] == 'n' && checkN(i,j,kx,ky))
				return 1;
			if(s[i][j] == 'q' && checkQ(i,j,kx,ky))
				return 1;
			if(s[i][j] == 'r' && checkR(i,j,kx,ky))
				return 1;
			if(s[i][j] == 'b' && checkB(i,j,kx,ky))
				return 1;
		}
	return 0;
}

int check(int kx , int ky) {
	for( int i = 1 ; i <= 8 ; i++ )
		for( int j = 1 ; j <= 8 ; j++ ) {
			if(s[i][j] == 'N' && checkN(i,j,kx,ky))
				return 1;
			if(s[i][j] == 'Q' && checkQ(i,j,kx,ky))
				return 1;
			if(s[i][j] == 'R' && checkR(i,j,kx,ky))
				return 1;
			if(s[i][j] == 'B' && checkB(i,j,kx,ky))
				return 1;
		}
	return 0;
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		ans = 0;
		for( int i = 1 ; i <= 8 ; i++ )
			scanf("%s",s[i]+1);
		for( int i = 1 ; i <= 8 ; i++ )
			for( int j = 1 ; j <= 8 ; j++ ) {
					if(s[i][j] == 'K')
						my_kx = i , my_ky = j;
					else if(s[i][j] == 'k')
						op_kx = i , op_ky = j;
				}
		for( int j = 1 ; j <= 8 ; j++ )
			if(s[2][j] == 'P' && s[1][j] == '#') {
				s[2][j] = '#';
				s[1][j] = '.';
				if(checkInvalid(my_kx,my_ky)) {
					s[1][j] = '#';
					s[2][j] = 'P';
					continue;
				}
				s[1][j] = 'Q';
				ans += check(op_kx,op_ky);
				s[1][j] = 'R';
				ans += check(op_kx,op_ky);
				s[1][j] = 'B';
				ans += check(op_kx,op_ky);
				s[1][j] = 'N';
				ans += check(op_kx,op_ky);
				break;
			}
		printf("%d\n",ans);
	}
	return 0;
}
