#include <bits/stdc++.h>
#define maxn 100003
#define mod 998244353
using namespace std;
typedef long long LL;

struct Mat {
	int** ways;
	Mat() {
		ways = new int*[2];
		ways[0] = new int[2];
		ways[1] = new int[2];
	}
};

int T,n,e;
stack<int> st;
char str[maxn];
int oper[maxn];
int next02[maxn];

int makeOp(int a, int b, char c) {
	int res = -1;
	if(c == '&')
		res = a && b;
	else if(c == '|')
		res = a || b;
	else
		res = a != b;
	return res;
}

void multMat(Mat* mat, Mat* matL, Mat* matR, char c) {
	mat->ways[0][0] = mat->ways[0][1] = mat->ways[1][0] = mat->ways[1][1] = 0;
	for( int i = 0 ; i < 2 ; i++ )
		for( int j = 0 ; j < 2 ; j++ )
			for( int k = 0 ; k < 2 ; k++ ) {
				int val = makeOp(j,k,c);
				int add = (LL) matL->ways[i][j] * matR->ways[i][k] % mod;
				mat->ways[i][val] = ( mat->ways[i][val] + add ) % mod;
			}
}

Mat* f(int left, int right) {
	Mat* mat = new Mat();
	if(left == right)
		mat->ways[0][0] = mat->ways[0][1] = mat->ways[1][0] = mat->ways[1][1] = 2;
	else {
		int index = oper[left];
		Mat* matL = f(left+1, index-1);
		Mat* matR = f(index+1, right-1);
		multMat(mat, matL, matR, str[index]);
		delete matL;
		delete matR;
	}
	return mat;
}

int calcPow(int x, int y) {
	if(y == 0)
		return 1;
	int res = calcPow(x, y/2);
	res = (LL) res * res % mod;
	if(y & 1)
		res = (LL) res * x % mod;
	return res;
}

int calcRev(int x) {
	return calcPow(x, mod-2);
}

void output(Mat* mat) {
	int res;
	int q = calcRev( calcPow(16,e) );
	res = ( (LL) mat->ways[0][0] * mat->ways[1][0] % mod ) * q % mod;
	printf("%d ",res);
	res = ( (LL) mat->ways[0][1] * mat->ways[1][1] % mod ) * q % mod;
	printf("%d ",res);
	res = ( (LL) mat->ways[0][0] * mat->ways[1][1] % mod ) * q % mod;
	printf("%d ",res);
	res = ( (LL) mat->ways[0][1] * mat->ways[1][0] % mod ) * q % mod;
	printf("%d\n",res);
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%s",str+1);
		n = strlen(str+1);
		e = 0;
		memset(oper, -1, sizeof(oper));
		memset(next02, -1, sizeof(next02));
		for( int i = 1 ; i <= n ; i++ ) {
			if(str[i] == '(')
				st.push(i);
			else if(str[i] == ')') {
				next02[st.top()] = i;
				next02[i] = st.top();
				st.pop();
			}
			else if(str[i] != '#')
				oper[st.top()] = i;
			else
				e++;
		}
		Mat* mat = f(1,n);
		output(mat);
		delete mat;
	}
	return 0;
}
