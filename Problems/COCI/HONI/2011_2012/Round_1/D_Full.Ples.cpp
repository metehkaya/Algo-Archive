#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int n,ans;
vector<int> h[2][2];

int f(vector<int>& vmore , vector<int>& vless) {
    vector<pair<int,int>> v;
    for(int x : vmore)
        v.push_back(make_pair(x,1));
    for(int x : vless)
        v.push_back(make_pair(x,0));
    sort(v.begin(),v.end());
    int res = 0 , curr = 0;
    for(auto p : v) {
        int x = p.fi , t = p.se;
        if(t == 1)
            curr++;
        else if(curr > 0) {
            res++;
            curr--;
        }
    }
    return res;
}

int main() {
    scanf("%d",&n);
    for( int g = 0 ; g < 2 ; g++ )
        for( int i = 0 ; i < n ; i++ ) {
            int x;
            scanf("%d",&x);
            if(x > 0)
                h[g][0].push_back(x);
            else
                h[g][1].push_back(-x);
        }
    ans += f(h[0][0],h[1][1]);
    ans += f(h[1][0],h[0][1]);
    printf("%d\n",ans);
	return 0;
}