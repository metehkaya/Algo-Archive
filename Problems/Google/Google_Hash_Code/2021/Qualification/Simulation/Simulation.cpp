#include <bits/stdc++.h>
#define fi first
#define se second
#define maxc 1000
#define maxm 100000
#define maxn 100000
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> pi;
typedef pair<pi,int> pii;

int d,n,m,c,p;
int eSrc[maxm];
int eDist[maxm];
string eName[maxm];
vector<int> carEdgeId[maxc];
map<string,int> mpEdgeName;

int schN;
int cycleTotal[maxn];
vector<int> schVertex;
vector<int> prefixSum[maxn];
vector<int> schEdges[maxn];

int currSchEdgeId[maxn];
queue<pii> qCars[maxm];

void input() {
	ifstream inFile;
	inFile.open("input.txt");
	inFile >> d >> n >> m >> c >> p;
	for( int i = 0 ; i < m ; i++ ) {
		int dest;
		inFile >> eSrc[i] >> dest >> eName[i] >> eDist[i];
		mpEdgeName[eName[i]] = i;
	}
	for( int i = 0 ; i < c ; i++ ) {
		int k,id;
		string e;
		inFile >> k;
		for( int j = 0 ; j < k ; j++ ) {
			inFile >> e;
			id = mpEdgeName[e];
			carEdgeId[i].pb(id);
		}
	}
	inFile.close();
}

void output() {
	ifstream outFile;
	outFile.open("output.txt");
	outFile >> schN;
	for( int i = 0 ; i < schN ; i++ ) {
		int u,e,sum=0;
		outFile >> u >> e;
		schVertex.pb(u);
		for( int j = 0 ; j < e ; j++ ) {
			int len;
			string name;
			outFile >> name >> len;
			int id = mpEdgeName[name];
			schEdges[u].pb(id);
			sum += len;
			prefixSum[u].pb(sum);
		}
		prefixSum[u][e-1] = 0;
		cycleTotal[u] = sum;
	}
	outFile.close();
}

void sim() {
	int score = 0;
	int arrived = 0;
	for( int i = 0 ; i < c ; i++ ) {
		int eId = carEdgeId[i][0];
		qCars[eId].push(pii( pi(i,0) , 0 ));
	}
	for( int t = 0 ; t <= d ; t++ ) {
		for( int sv = 0 ; sv < schN ; sv++ ) {
			int u = schVertex[sv];
			int scheid = currSchEdgeId[u];
			int eid = schEdges[u][scheid];
			if(!qCars[eid].empty()) {
				pii car = qCars[eid].front();
				int cid = car.fi.fi;
				int peid = car.fi.se + 1;
				int arrt = car.se;
				if(t >= arrt) {
					qCars[eid].pop();
					int path = carEdgeId[cid].size();
					int reeleid = carEdgeId[cid][peid];
					if(peid == path-1) {
						if(t+eDist[reeleid] <= d) {
							arrived++;
							score += p + (d - (t+eDist[reeleid]));
						}
					}
					else
						qCars[reeleid].push( pii( pi(cid,peid) , t+eDist[reeleid] ) );
				}
			}
			bool nxtEdge = ( ((t+1) % cycleTotal[u]) == prefixSum[u][scheid] );
			currSchEdgeId[u] = (currSchEdgeId[u]+nxtEdge) % schEdges[u].size();
		}
	}
	printf("%d , %d / %d\n",score,arrived,c);
}

int main() {
	input();
	output();
	sim();
	return 0;
}
