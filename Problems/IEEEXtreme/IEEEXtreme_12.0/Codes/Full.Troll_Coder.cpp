#include <bits/stdc++.h>
#define maxn 100
using namespace std;

int n,fv;
int mySeq[maxn];

int main() {
	cin >> n;
	cout << "Q";
	for( int i = 0 ; i < n ; i++ )
		cout << " 0";
	cout << endl;
	cout.flush();
	cin >> fv;
	for( int i = 0 , v ; i < n - 1 ; i++ ) {
		cout << "Q";
		for( int j = 0 ; j < i ; j++ )
			cout << " 0";
		cout << " 1";
		for( int j = i + 1 ; j < n ; j++ )
			cout << " 0";
		cout << endl;
		cout.flush();
		cin >> v;
		if( v < fv )
			mySeq[i] = 0;
		else
			mySeq[i] = 1;
	}
	int sum = 0;
	for( int i = 0 ; i < n - 1 ; i++ )
		sum += 1 - mySeq[i];
	if( sum < fv )
		mySeq[n-1] = 0;
	else
		mySeq[n-1] = 1;
	cout << "A";
	for( int i = 0 ; i < n ; i++ )
		cout << " " << mySeq[i];
	cout << endl;
	cout.flush();
	return 0;
}