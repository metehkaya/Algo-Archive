#include <bits/stdc++.h>
#define maxn 100
#define maxb (1 << 20)
using namespace std;

int n,t;
int b[maxn];
int bm[maxn];
int oldDp[maxb];
int newDp[maxb];
map<string,int> hashh;

int processLine( string line ) {
	
	int bmask = 0;
	int sz = line.size();
	
	for( int l = 0 , r ; l < sz ; l = r + 1 ) {
		r = l;
		string word = "";
		while( r < sz && line[r] != ' ' )
			word += line[r++];
		if( !hashh[word] )
			hashh[word] = ++t;
		bmask |= ( 1 << (hashh[word] - 1) );
	}
	
	return bmask;
	
}

int main() {
	
	int c;
	while( scanf( "%d " , &c ) != -1 ) {
		b[n] = c;
		string line;
		getline( cin , line );
		bm[n] = processLine( line );
		n++;
	}
	
	memset( oldDp , -1 , sizeof( oldDp ) );
	oldDp[0] = 0 , oldDp[bm[0]] = b[0];
	
	for( int type = 1 ; type < n ; type++ ) {
		for( int i = 0 ; i < maxb ; i++ )
			newDp[i] = oldDp[i];
		for( int i = 0 ; i < maxb ; i++ )
			if( oldDp[i] != -1 ) {
				int bmask = ( i | bm[type] );
				if( newDp[bmask] == -1 || oldDp[i] + b[type] < newDp[bmask] )
					newDp[bmask] = oldDp[i] + b[type];
			}
		for( int i = 0 ; i < maxb ; i++ )
			oldDp[i] = newDp[i];
	}
	
	printf( "%d\n" , oldDp[(1<<t)-1] );
	
	return 0;

}
