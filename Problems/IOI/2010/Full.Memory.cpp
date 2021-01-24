#include <bits/stdc++.h>
#include "memory.h"
#include "grader.h"
#define pb push_back
using namespace std;

vector<int> v[25];

void play() {
	for( int i = 1 ; i <= 50 ; i++ ) {
		char c = faceup(i);
		v[c-'A'].pb(i);
	}
	for( int i = 0 ; i < 25 ; i++ ) {
		faceup(v[i][0]);
		faceup(v[i][1]);
	}
}
