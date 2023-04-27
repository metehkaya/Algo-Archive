#include <bits/stdc++.h>
#define maxn 500001
#define pb push_back
using namespace std;
typedef long long LL;

struct item {
	int c,q,id;
}ar[maxn];

bool comp(const item& a , const item& b) {
	return a.c*b.q < b.c*a.q;
}

bool operator<(const item& a , const item& b) {
	return a.q < b.q;
}

LL w;
int n;
double ansCost;
int ansIdx,ansCnt;

void solve(bool printSol) {
	LL currSum = 0;
	int currCnt = 0;
	priority_queue<item> heap;
	for( int i = 1 ; i <= n ; i++ ) {
		currCnt++;
		currSum += ar[i].q;
		heap.push(ar[i]);
		while(ar[i].c * currSum > w * ar[i].q) {
			item it = heap.top();
			heap.pop();
			currCnt--;
			currSum -= it.q;
		}
		if(printSol) {
			if(i == ansIdx) {
				vector<int> ans;
				while(!heap.empty()) {
					ans.pb(heap.top().id);
					heap.pop();
				}
				int sz = ans.size();
				sort(ans.begin(),ans.end());
				printf("%d\n",sz);
				for( int i = 0 ; i < sz ; i++ )
					printf("%d\n",ans[i]);
				break;
			}
		}
		else {
			double cost = (double) ar[i].c / ar[i].q * currSum;
			if(currCnt > ansCnt) {
				ansIdx = i;
				ansCnt = currCnt;
				ansCost = cost;
			}
			else if(currCnt == ansCnt && cost < ansCost) {
				ansIdx = i;
				ansCost = cost;
			}
		}
	}
}

int main() {
	scanf("%d%lld",&n,&w);
	for( int i = 1 ; i <= n ; i++ ) {
		ar[i].id = i;
		scanf("%d%d",&ar[i].c,&ar[i].q);
	}
	sort(ar+1,ar+n+1,comp);
	solve(false);
	if(ansIdx == 0)
		puts("0");
	else
		solve(true);
	return 0;
}
