#include <bits/stdc++.h>
#define maxs 100000
#define pb push_back
using namespace std;

int T,n,b;
int k[10];
vector<int> v[10];
vector<int> valA,valB;

void reset() {
	valA.clear();
	valB.clear();
	for( int i = 0 ; i < n ; i++ )
		v[i].clear();
}

void fill(int ind, int end, int sum, vector<int>& vals) {
	if(ind == end) {
		vals.pb(sum);
		return;
	}
	for( int i = 0 ; i < k[ind] ; i++ )
		if( sum <= b - v[ind][i] )
			fill(ind+1, end, sum+v[ind][i], vals);
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		scanf("%d%d",&b,&n);
		for( int i = 0 ; i < n ; i++ )
			scanf("%d",&k[i]);
		for( int i = 0 , x ; i < n ; i++ )
			for( int j = 0 ; j < k[i] ; j++ ) {
				scanf("%d",&x);
				v[i].pb(x);
			}
		int mult = 1;
		int last = 0;
		while( last < n && mult*k[last] <= maxs )
			mult *= k[last++];
		fill(0, last, 0, valA);
		fill(last, n, 0, valB);
		sort(valA.begin(), valA.end());
		sort(valB.begin(), valB.end());
		int indexA = valA.size()-1;
		while( indexA >= 0 && valA[indexA] > b )
			indexA--;
		if(indexA == -1)
			puts("0");
		else {
			if(last == n)
				printf("%d\n",valA[indexA]);
			else {
				int indexB = valB.size()-1;
				while( indexB >= 0 && valA[indexA] > b - valB[indexB] )
					indexB--;
				int best = 0;
				if(indexB != -1)
					best = valA[indexA] + valB[indexB];
				while(--indexA >= 0)
					while(indexB+1 < (int) valB.size() && valA[indexA] <= b - valB[indexB+1])
						best = max( best , valA[indexA] + valB[++indexB] );
				printf("%d\n", best);
			}
		}
	}
	return 0;
}
