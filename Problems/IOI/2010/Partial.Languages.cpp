#include <bits/stdc++.h>
#include "grader.h"
#define maxl 56
#define maxc 100
#define maxt 65536
#define pb push_back
using namespace std;
typedef pair<int,int> pi;
typedef pair<pi,pi> pii;
typedef pair<pii,int> piii;

set<piii> s;

void excerpt(int tokens[maxc]) {
	int score[maxl];
	for( int l = 0 ; l < maxl ; l++ ) {
		score[l] = 0;
		for( int i = 0 ; i <= maxc-4 ; i++ ) {
			pi p1 = pi(tokens[i],tokens[i+1]);
			pi p2 = pi(tokens[i+2],tokens[i+3]);
			piii p = piii(pii(p1,p2),l);
			score[l] += s.count(p);
		}
	}	
	int bestScore = -1;
	vector<int> candidates;
	for( int l = 0 ; l < maxl ; l++ )
		if(score[l] > bestScore) {
			bestScore = score[l];
			candidates.clear();
			candidates.pb(l);
		}
		else if(score[l] == bestScore)
			candidates.pb(l);
	int sz = candidates.size();
	srand(time(NULL));
	int l = candidates[rand()%sz];
	l = language(l);
	for( int i = 0 ; i <= maxc-4 ; i++ ) {
		pi p1 = pi(tokens[i],tokens[i+1]);
		pi p2 = pi(tokens[i+2],tokens[i+3]);
		piii p = piii(pii(p1,p2),l);
		s.insert(p);
	}
}
