#include <bits/stdc++.h>
#define fi first
#define se second
#define maxb 19
#define maxm 59
#define maxk 393
#define maxn 400001
#define maxs 100000
#define mod 1000000007
#define pb push_back
using namespace std;
typedef pair<int,int> pi;

int T,n,k,m;
int res[maxn];
bool in[maxk];
bool out[maxk];
int isState[maxk];
int isMagic[maxs];
int dp[maxn][maxm];
vector<pi>G;
vector<int>magics;

bool check(int val) {
    if(val <= 1)
        return false;
    for( int i = 2 ; i*i <= val ; i++ )
        if( val%i == 0 )
            return false;
    return true;
}

int getDig(int val) {
    int nDig = 0;
    while(val > 0) {
        nDig++;
        val /= 10;
    }
    return nDig;
}

void findMagic() {
    memset(isMagic, -1, sizeof(isMagic));
    for( int a = 0 ; a <= 9 ; a++ )
        for( int b = 0 ; b <= 9 ; b++ )
            for( int c = 0 ; c <= 9 ; c++ )
                if( check(a+b+c) ) {
                	if(a)
                		res[3]++;
                    for( int d = 0 ; d <= 9 ; d++ )
                        if( check(b+c+d) && check(a+b+c+d) ) {
                        	if(a)
                        		res[4]++;
                            for( int e = 0 ; e <= 9 ; e++ )
                                if( check(c+d+e) && check(b+c+d+e) && check(a+b+c+d+e) ) {
                                	if(a)
                                		res[5]++;
                                    int val = 10000*a+1000*b+100*c+10*d+1*e;
                                    isMagic[val] = k++;
                                    magics.pb(val);
                                }
                        }
                }
}

void makeGraph() {
    for( int i = 0 ; i < k ; i++ ) {
        int val1 = magics[i];
        for( int j = 0 ; j <= 9 ; j++ ) {
            int val2 = (val1 % 10000) * 10 + j;
            if(isMagic[val2] != -1) {
                out[i] = true;
                in[isMagic[val2]] = true;
                G.pb(pi(i,isMagic[val2]));
            }
        }
    }
    memset(isState, -1, sizeof(isState));
    for( int i = 0 ; i < k ; i++ )
        if(in[i] && out[i])
            isState[i] = m++;
}

void calcDP() {
    res[1] = 9;
    res[2] = 90;
    int e = (int) G.size();
    for( int i = 0 ; i < e ; i++ ) {
        int u = G[i].fi;
        int v = G[i].se;
        if(getDig(magics[u]) == 5) {
            res[6]++;
            if(isState[v] != -1)
                dp[6][isState[v]]++;
        }
    }
    for( int i = 6 ; i < maxn-1 ; i++ )
        for( int j = 0 ; j < e ; j++ ) {
            int u = G[j].fi;
            int v = G[j].se;
            int a = isState[u];
            int b = isState[v];
            if(a != -1) {
                res[i+1] = ( res[i+1] + dp[i][a] ) % mod;
                if(b != -1)
                    dp[i+1][b] = ( dp[i+1][b] + dp[i][a] ) % mod;
            }
        }
}

int main() {
    findMagic();
    makeGraph();
    calcDP();
    scanf("%d",&T);
    for( int tc = 1 ; tc <= T ; tc++ ) {
        scanf("%d",&n);
        printf("%d\n",res[n]);
    }
    return 0;
}
