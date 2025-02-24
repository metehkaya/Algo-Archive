#include <bits/stdc++.h>
#define maxn 500001
using namespace std;
typedef long long LL;

int n,m,t;
int ar[maxn];
int dt[maxn];
int ft[maxn];
int par[maxn];
LL tree[4*maxn];
vector<int> adj[maxn];

void dfs(int u , int dad) {
    dt[u] = ++t;
    for(int v : adj[u])
        dfs(v,u);
    ft[u] = t;
}

void update(int cx , int cy , int qx , int qy , int val , int id) {
    if(qy < cx or cy < qx)
        return;
    if(qx <= cx and cy <= qy) {
        tree[id] += val;
        return;
    }
    int mid = (cx + cy) >> 1;
    update(cx,mid,qx,qy,val,2*id);
    update(mid+1,cy,qx,qy,val,2*id+1);
}

LL query(int cx , int cy , int q , int id) {
    if(q < cx or cy < q)
        return 0;
    if(cx == cy)
        return tree[id];
    int mid = (cx + cy) >> 1;
    LL l = query(cx,mid,q,2*id);
    LL r = query(mid+1,cy,q,2*id+1);
    return l+r+tree[id];
}

int main() {
	scanf("%d%d%d",&n,&m,&ar[1]);
	for( int i = 2 ; i <= n ; i++ ) {
	    scanf("%d%d",&ar[i],&par[i]);
	    adj[par[i]].push_back(i);
	}
	dfs(1,0);
	for( int i = 1 ; i <= n ; i++ )
	    update(1,n,dt[i],dt[i],ar[i],1);
    while(m--) {
        int u,x;
        string type;
        cin >> type;
        if(type == "p") {
            scanf("%d%d",&u,&x);
            if(dt[u] < ft[u])
                update(1,n,dt[u]+1,ft[u],x,1);
        }
        else {
            scanf("%d",&u);
            printf("%lld\n",query(1,n,dt[u],1));
        }
    }
	return 0;
}