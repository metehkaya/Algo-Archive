// Encoder

#include <bits/stdc++.h>
#include "encoder.h"
#include "grader.h"
#define maxn 1000
#define pb push_back
using namespace std;

int dist[maxn];
vector<int> adj[maxn];

void encode(int n, int h, int m, int *v1, int *v2) {
	for( int i = 0 ; i < m ; i++ ) {
		int u = v1[i] , v = v2[i];
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for( int src = 0 ; src < h ; src++ ) {
		queue<int> Q;
		memset(dist,-1,sizeof(dist));
		Q.push(src);
		dist[src] = 0;
		while(!Q.empty()) {
			int u = Q.front();
			Q.pop();
			int deg = adj[u].size();
			for( int i = 0 ; i < deg ; i++ ) {
				int v = adj[u][i];
				if(dist[v] == -1) {
					Q.push(v);
					dist[v] = dist[u]+1;
				}
			}
		}
		for( int i = 0 ; i < n ; i++ )
			for( int j = 0 ; j < 10 ; j++ )
				if(dist[i]&(1<<j))
					encode_bit(1);
				else
					encode_bit(0);
	}
}

// Decoder

#include <bits/stdc++.h>
#include "decoder.h"
#include "grader.h"
using namespace std;

void decode(int n, int h) {
	for( int i = 0 ; i < h ; i++ )
		for( int j = 0 ; j < n ; j++ ) {
			int val = 0;
			for( int k = 0 ; k < 10 ; k++ )
				val |= (decode_bit() * (1<<k));
			hops(i,j,val);
		}
}
