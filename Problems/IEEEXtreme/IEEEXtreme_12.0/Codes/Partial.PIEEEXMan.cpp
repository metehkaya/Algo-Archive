#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pi;

int N,M,k;
int myR,myC,opR,opC;

int goo[256][2];
bool notEaten[61][61];
int dist[61][61][61][61];
int dir[4][2] = { {-1,0} , {+1,0} , {0,-1} , {0,+1} };

vector<pi>v;
string str[61];

void bfs( int R , int C ) {
	queue<pi>Q;
	dist[R][C][R][C] = 0;
	Q.push( pi( R , C ) );
	while( !Q.empty() ) {
		pi tmp = Q.front();
		Q.pop();
		int r = tmp.fi , c = tmp.se;
		for( int i = 0 ; i < 4 ; i++ ) {
			int r1 = r + dir[i][0];
			int c1 = c + dir[i][1];
			int r2 = r1 + dir[i][0];
			int c2 = c1 + dir[i][1];
			if( str[r1][c1] != '#' )
				if( r2 >= 0 && r2 < N && c2 >= 0 && c2 < M )
					if( str[r2][c2] != '#' && dist[R][C][r2][c2] == -1 ) {
						Q.push( pi( r2 , c2 ) );
						dist[R][C][r2][c2] = dist[R][C][r][c] + 1;
					}
		}
	}
}

bool check( int r , int c , int way , int d ) {
	int r1 = myR + dir[way][0];
	int c1 = myC + dir[way][1];
	int r2 = r1 + dir[way][0];
	int c2 = c1 + dir[way][1];
	if( str[r1][c1] == '#' )
		return false;
	if( r2 < 0 || r2 >= N || c2 < 0 || c2 >= M )
		return false;
	if( str[r2][c2] == '#' )
		return false;
	if( dist[r2][c2][r][c] == d )
		return true;
	return false;
}

int main() {

	goo['U'][0] = -1 , goo['U'][1] = 0;
	goo['D'][0] = +1 , goo['D'][1] = 0;
	goo['L'][0] = 0 , goo['L'][1] = -1;
	goo['R'][0] = 0 , goo['R'][1] = +1;

	cin >> N >> M;
	N = 2*N+1 , M = 2*M+1;
	for( int i = 0 ; i < N ; i++ )
		cin >> str[i];

	for( int i = 0 ; i < N ; i++ )
		for( int j = 0 ; j < M ; j++ ) {
			if( str[i][j] == '1' )
				myR = i , myC = j;
			else if( str[i][j] == '2' )
				opR = i , opC = j;
			else if( str[i][j] == '@' ) {
				k++;
				v.pb( pi( i , j ) );
				notEaten[i][j] = true;
			}
		}

	memset( dist , -1 , sizeof(dist) );
	for( int i = 1 ; i < N ; i += 2 )
		for( int j = 1 ; j < M ; j += 2 )
			bfs( i , j );

	while( true ) {

		int bestDist = INT_MAX , bestDir = -1;
		for( int i = 0 ; i < k ; i++ ) {
			int r = v[i].fi , c = v[i].se;
			int d1 = dist[myR][myC][r][c];
			int d2 = dist[opR][opC][r][c];
			if( notEaten[r][c] && d1 != -1 && d1 < bestDist && ( d2 == -1 || d1 <= d2 ) ) {
				bestDist = d1;
				for( int j = 0 ; j < 4 ; j++ )
					if( check( r , c , j , d1 - 1 ) )
						bestDir = j;
			}
		}

		switch(bestDir) {
			case -1:
				cout << "W" << endl;
				cout.flush();
				break;
			case 0:
				cout << "U" << endl;
				cout.flush();
				myR -= 2;
				break;
			case 1:
				cout << "D" << endl;
				cout.flush();
				myR += 2;
				break;
			case 2:
				cout << "L" << endl;
				cout.flush();
				myC -= 2;
				break;
			case 3:
				cout << "R" << endl;
				cout.flush();
				myC += 2;
				break;
		}

		notEaten[myR][myC] = false;
		string inp;
		cin >> inp;
		if( inp.length() == 2 )
			break;
		char ccc = inp[0];
		opR += 2*goo[ccc][0] , opC += 2*goo[ccc][1];
		notEaten[opR][opC] = false;

	}

	return 0;
	
}