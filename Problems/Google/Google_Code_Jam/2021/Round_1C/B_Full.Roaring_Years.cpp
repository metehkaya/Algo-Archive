#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int T,dstr;
string str;
ull ans,temp;

void reset() {
	ans = 9;
	for( int i = 0 ; i < 18 ; i++ )
		ans = 10*ans+9;
}

void output(int tc) {
	printf("Case #%d: ",tc);
	cout << ans << endl;
}

void input() {
	cin >> str;
}

int getDig(int num) {
	int d = 0;
	while(num) {
		d++;
		num /= 10;
	}
	return d;
}

void f(int head) {
	ull x = 0;
	int totald = 0;
	bool fine = false;
	for( int num = head ; totald < 19 ; num++ ) {
		int d = getDig(num);
		totald += d;
		if(totald > 19)
			break;
		for( int i = 0 ; i < d ; i++ )
			x *= 10;
		x = x + num;
		if(fine) {
			if(x > temp && x < ans)
				ans = x;
		}
		else
			fine = true;
	}
}

void solve() {
	dstr = str.length();
	temp = 0;
	for( int i = 0 ; i < dstr ; i++ )
		temp = 10*temp + (str[i]-'0');
	int head = 0;
	for( int i = 0 ; i < min(dstr,9) ; i++ ) {
		head = 10*head + str[i]-'0';
		for( int j = 0 ; j <= 100 ; j++ )
			f(head+j);
	}
	head = 1;
	for( int i = 0 ; i <= 9 ; i++ ) {
		for( int j = 0 ; j < min(head,20) ; j++ )
			f(head-j);
		head *= 10;
	}
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		input();
		solve();
		output(tc);
	}
	return 0;
}
