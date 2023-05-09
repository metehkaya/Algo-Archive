#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long LL;

LL x,y,X,Y;
vector<string> ans;

LL gcd(LL a , LL b) {
	if(!b)
		return a;
	return gcd(b,a%b);
}

string toStr(LL a) {
	string s = "";
	while(a) {
		s.push_back('0'+(a%10));
		a /= 10;
	}
	reverse(s.begin(),s.end());
	return s;
}

void addXor(LL a , LL b) {
	ans.pb(toStr(a) + " ^ " + toStr(b));
}

void addSum(LL a , LL b) {
	ans.pb(toStr(a) + " + " + toStr(b));
}

void handleMult(LL a , LL b) {
	if(a == b)
		return;
	LL mult = b / a;
	int k;
	for( k = 1 ; (1LL<<k) <= mult ; k++ ) {
		LL K = (1LL << (k-1));
		LL Ka = K*a;
		addSum(Ka,Ka);
	}
	LL curr = (a << (--k));
	for( k = k-1 ; k >= 0 ; k-- )
		if(mult & (1LL << k)) {
			LL add = (a << k);
			addSum(curr,add);
			curr += add;
		}
}

int main() {
	scanf("%lld",&x);
	for( int k = 1 ; true ; k++ ) {
		LL K = (1LL << k);
		LL Kx = K*x;
		y = (Kx^x);
		if(gcd(x,y) == 1) {
			handleMult(x,Kx);
			addXor(Kx,x);
			break;
		}
	}
	for( LL mult = 1 ; true ; mult++ ) {
		Y = y*mult;
		if(Y%2)
			X = Y-1;
		else
			X = Y+1;
		if(X % x == 0) {
			handleMult(x,X);
			handleMult(y,Y);
			addXor(X,Y);
			break;
		}
	}
	int cnt = ans.size();
	printf("%d\n",cnt);
	for( int i = 0 ; i < cnt ; i++ )
		printf("%s\n",ans[i].c_str());
	return 0;
}
