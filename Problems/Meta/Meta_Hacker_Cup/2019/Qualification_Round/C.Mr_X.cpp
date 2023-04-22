#include <bits/stdc++.h>
#define fi first
#define se second
#define maxn 305
#define pb push_back
using namespace std;
typedef pair<int,int> pi;

int T,n;
string str;
vector<pi> v;
pi res[maxn];
int nxt[maxn];
stack<int> st;

void io() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

void reset() {
	v.clear();
	memset(nxt,-1,sizeof(nxt));
}

pi getToken(char c) {
	if( c == '0' )
		return pi(0,0);
	if( c == '1' )
		return pi(1,1);
	if( c == 'x' )
		return pi(0,1);
	if( c == 'X' )
		return pi(1,0);
	return pi(-1,-1);
}

bool comp(pi a , pi b) {
	return a.se - a.fi < b.se - b.fi;
}

pi opAnd(pi a , pi b) {
	return pi( ( a.fi & b.fi ) , ( a.se & b.se ) );
}

pi opOr(pi a , pi b) {
	return pi( ( a.fi | b.fi ) , ( a.se | b.se ) );
}

pi opXor(pi a , pi b) {
	return pi( ( a.fi ^ b.fi ) , ( a.se ^ b.se ) );
}

pi makeOp(pi a , pi b , char op) {
	if( op == '&' )
		return opAnd(a,b);
	else if( op == '|' )
		return opOr(a,b);
	else
		return opXor(a,b);
}

void printResult(int tc , pi ans) {
	int diff = (ans.fi ^ ans.se);
	printf("Case #%d: %d\n",tc,diff);
}

int main() {
	io();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		cin >> str;
		n = str.length();
		if(n == 1) {
			printResult(tc,getToken(str[0]));
			continue;
		}
		for( int i = 0 ; i < n ; i++ ) {
			if(str[i] == '(')
				st.push(i);
			else if(str[i] == ')') {
				int ind = st.top();
				st.pop();
				nxt[ind] = i;
				nxt[i] = ind;
				v.pb(pi(ind,i));
			}
		}
		sort(v.begin() , v.end() , comp);
		for( int i = 0 ; i < (int) v.size() ; i++ ) {
			int l = v[i].fi , r = v[i].se;
			if(nxt[l+1] == -1) {
				nxt[l+1] = l+1;
				res[l+1] = getToken(str[l+1]);
			}
			if( nxt[r-1] == -1 ) {
				nxt[r-1] = r-1;
				res[r-1] = getToken(str[r-1]);
			}
			pi a = res[l+1];
			pi b = res[nxt[r-1]];
			char op = str[nxt[l+1]+1];
			res[l] = makeOp(a,b,op);
		}
		printResult(tc,res[0]);
	}
	return 0;
}
