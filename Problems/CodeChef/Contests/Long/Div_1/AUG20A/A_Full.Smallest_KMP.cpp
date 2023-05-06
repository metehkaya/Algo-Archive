#include <bits/stdc++.h>
#define maxk 26
#define maxn 100003
using namespace std;

int T,n,m;
char s[maxn];
char t[maxn];
int scnt[maxk];
int tcnt[maxk];

void reset() {
	memset(scnt,0,sizeof(scnt));
	memset(tcnt,0,sizeof(tcnt));
}

int main() {
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		reset();
		scanf("%s%s",s,t);
		n = strlen(s);
		m = strlen(t);
		for( int i = 0 ; i < n ; i++ )
			scnt[s[i]-'a']++;
		for( int i = 0 ; i < m ; i++ )
			tcnt[t[i]-'a']++;
		int idx;
		for( idx = 1 ; idx < m ; idx++ )
			if(t[0] != t[idx])
				break;
		for( int i = 0 ; i < maxk ; i++ ) {
			char c = 'a'+i;
			if(t[0] == c) {
				bool printC = (idx == m || t[idx] > t[0]);
				if(printC)
					for( int j = 0 ; j < scnt[i]-tcnt[i] ; j++ )
						printf("%c",c);
				printf("%s",t);
				if(!printC)
					for( int j = 0 ; j < scnt[i]-tcnt[i] ; j++ )
						printf("%c",c);
			}
			else
				for( int j = 0 ; j < scnt[i]-tcnt[i] ; j++ )
					printf("%c",c);
		}
		puts("");
	}
	return 0;
}
