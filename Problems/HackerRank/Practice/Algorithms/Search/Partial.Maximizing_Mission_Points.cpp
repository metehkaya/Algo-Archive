#include <bits/stdc++.h>
#define maxn 200000
#define pb push_back
using namespace std;
typedef long long LL;
typedef vector<int> vi;

struct data {
	int latitude;
	int longitude;
	int height;
	int point;
}ar[maxn];

bool comp(data &a, data &b) {
	return a.height < b.height;
}

struct node {
	int lowLatitude;
	int highLatitude;
	int lowLongitude;
	int highLongitude;
	node(int _lowLatitude, int _highLatitude, int _lowLongitude, int _highLongitude) {
		lowLatitude = _lowLatitude;
		highLatitude = _highLatitude;
		lowLongitude = _lowLongitude;
		highLongitude = _highLongitude;
	}
};

vector<node> getChildren(int lowLatitude, int highLatitude, int lowLongitude, int highLongitude) {
	vector<node> children;
	if(lowLatitude < highLatitude && lowLongitude == highLongitude) {
		int midLatitude = (lowLatitude + highLatitude) / 2;
		children.pb(node(lowLatitude,midLatitude,lowLongitude,highLongitude));
		children.pb(node(midLatitude+1,highLatitude,lowLongitude,highLongitude));
	}
	else if(lowLatitude == highLatitude && lowLongitude < highLongitude) {
		int midLongitude = (lowLongitude + highLongitude) / 2;
		children.pb(node(lowLatitude,highLatitude,lowLongitude,midLongitude));
		children.pb(node(lowLatitude,highLatitude,midLongitude+1,highLongitude));
	}
	else if(lowLatitude < highLatitude && lowLongitude < highLongitude) {
		int midLatitude = (lowLatitude + highLatitude) / 2;
		int midLongitude = (lowLongitude + highLongitude) / 2;
		children.pb(node(lowLatitude,midLatitude,lowLongitude,midLongitude));
		children.pb(node(lowLatitude,midLatitude,midLongitude+1,highLongitude));
		children.pb(node(midLatitude+1,highLatitude,lowLongitude,midLongitude));
		children.pb(node(midLatitude+1,highLatitude,midLongitude+1,highLongitude));
	}
	return children;
}

int n,dlat,dlong,n1,n2,k;
vi empty;
vi latitudes;
vi longitudes;
vector<LL> tree;
vector<vi> childrenIDs;
map<int,int> hashLatitude;
map<int,int> hashLongitude;

void init(int lowLatitude, int highLatitude, int lowLongitude, int highLongitude, int id) {
	tree.pb(0);
	childrenIDs.pb(empty);
	vector<node> children = getChildren(lowLatitude, highLatitude, lowLongitude, highLongitude);
	for( int i = 0 ; i < (int) children.size() ; i++ ) {
		int _lowLatitude = children[i].lowLatitude;
		int _highLatitude = children[i].highLatitude;
		int _lowLongitude = children[i].lowLongitude;
		int _highLongitude = children[i].highLongitude;
		int childID = k++;
		childrenIDs[id].pb(childID);
		init(_lowLatitude, _highLatitude, _lowLongitude, _highLongitude, childID);
	}
}

void initTree() {
	k++;
	init(1,n1,1,n2,0);
}

void update(int lowLatitude, int highLatitude, int lowLongitude, int highLongitude, int id, int latitude, int longitude, LL score) {
	if(highLatitude < latitude || latitude < lowLatitude)
		return;
	if(highLongitude < longitude || longitude < lowLongitude)
		return;
	tree[id] = max(tree[id], score);
	vector<node> children = getChildren(lowLatitude, highLatitude, lowLongitude, highLongitude);
	for( int i = 0 ; i < (int) children.size() ; i++ ) {
		int _lowLatitude = children[i].lowLatitude;
		int _highLatitude = children[i].highLatitude;
		int _lowLongitude = children[i].lowLongitude;
		int _highLongitude = children[i].highLongitude;
		update(_lowLatitude, _highLatitude, _lowLongitude, _highLongitude, childrenIDs[id][i], latitude, longitude, score);
	}
}

LL query(int lowLatitude, int highLatitude, int lowLongitude, int highLongitude, int id, int latitudeMinus, int latitudePlus, int longitudeMinus, int longitudePlus) {
	if(highLatitude < latitudeMinus || latitudePlus < lowLatitude)
		return 0;
	if(highLongitude < longitudeMinus || longitudePlus < lowLongitude)
		return 0;
	if(latitudeMinus <= lowLatitude && highLatitude <= latitudePlus && longitudeMinus <= lowLongitude && highLongitude <= longitudePlus)
		return tree[id];
	LL best = 0;
	vector<node> children = getChildren(lowLatitude, highLatitude, lowLongitude, highLongitude);
	for( int i = 0 ; i < (int) children.size() ; i++ ) {
		int _lowLatitude = children[i].lowLatitude;
		int _highLatitude = children[i].highLatitude;
		int _lowLongitude = children[i].lowLongitude;
		int _highLongitude = children[i].highLongitude;
		LL score = query(_lowLatitude, _highLatitude, _lowLongitude, _highLongitude, childrenIDs[id][i], latitudeMinus, latitudePlus, longitudeMinus, longitudePlus);
		best = max(best, score);
	}
	return best;
}

int main() {
	scanf("%d%d%d",&n,&dlat,&dlong);
	for( int i = 0 ; i < n ; i++ ) {
		scanf("%d%d%d%d",&ar[i].latitude,&ar[i].longitude,&ar[i].height,&ar[i].point);
		latitudes.pb(ar[i].latitude);
		latitudes.pb(ar[i].latitude-dlat);
		latitudes.pb(ar[i].latitude+dlat);
		longitudes.pb(ar[i].longitude);
		longitudes.pb(ar[i].longitude-dlong);
		longitudes.pb(ar[i].longitude+dlong);
	}
	sort(latitudes.begin(), latitudes.end());
	for( int i = 0 ; i < 3*n ; i++ )
		if( i == 0 || latitudes[i] != latitudes[i-1] )
			hashLatitude[latitudes[i]] = ++n1;
	sort(longitudes.begin(), longitudes.end());
	for( int i = 0 ; i < 3*n ; i++ )
		if( i == 0 || longitudes[i] != longitudes[i-1] )
			hashLongitude[longitudes[i]] = ++n2;
	initTree();
	sort(ar,ar+n,comp);
	for( int i = 0 ; i < n ; i++ ) {
		int latitude = hashLatitude[ar[i].latitude];
		int latitudeMinus = hashLatitude[ar[i].latitude-dlat];
		int latitudePlus = hashLatitude[ar[i].latitude+dlat];
		int longitude = hashLongitude[ar[i].longitude];
		int longitudeMinus = hashLongitude[ar[i].longitude-dlong];
		int longitudePlus = hashLongitude[ar[i].longitude+dlong];
		LL score = query(1, n1, 1, n2, 0, latitudeMinus, latitudePlus, longitudeMinus, longitudePlus) + ar[i].point;
		if(score > 0)
			update(1, n1, 1, n2, 0, latitude, longitude, score);
	}
	printf("%lld\n",tree[0]);
	return 0;
}
