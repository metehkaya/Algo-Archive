#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int n;
vector<string> words[251];

int main() {
	scanf( "%d" , &n );
	for( int i = 0 , val ; i < n ; i++ ) {
		string word;
		cin >> word >> val;
		words[val].pb( word );
	}
	for( int i = 120 , cnt = 0 ; i <= 250 ; i++ )
		if( words[i].size() ) {
			sort( words[i].begin() , words[i].end() );
			for( int j = 0 ; j < words[i].size() ; j++ )
				cout << words[i][j] << " ";
			printf( "%d %d\n" , cnt + 1 , cnt + words[i].size() );
			cnt += words[i].size();
		}
	return 0;
}
