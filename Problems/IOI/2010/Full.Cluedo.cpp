#include <bits/stdc++.h>
#include "cluedo.h"
#include "grader.h"
using namespace std;

void Solve() {
	int ar[3] = {1,1,1};
	int res = Theory(ar[0],ar[1],ar[2]);
	while(res != 0) {
		ar[res-1]++;
		res = Theory(ar[0],ar[1],ar[2]);
	}
}
