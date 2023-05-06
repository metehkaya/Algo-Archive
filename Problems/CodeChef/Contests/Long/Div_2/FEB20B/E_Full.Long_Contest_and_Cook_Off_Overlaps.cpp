#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int PERIOD = 2000*12;

int T,M1,Y1,M2,Y2;
int sum[PERIOD+1];
int firstDay[2000][12];
int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};

bool checkExtra(int y, int m) {
	if(m == 1)
		if( ( (y+1)%4==0 && (y+1)%100!=0 ) || (y+1)%400==0 )
			return true;
	return false;
}

void calcFirstDay() {
	for( int i = 0 ; i < 2000*12-1 ; i++ ) {
		int m = i%12;
		int y = i/12;
		int nextM = (i+1)%12;
		int nextY = (i+1)/12;
		int add = checkExtra(y,m);
		firstDay[nextY][nextM] = ( firstDay[y][m] + days[m] + add ) % 7;
	}
}

bool checkIntersect(int day, int nDay) {
	int longS = (11 - day) % 7;
	int longE = longS + 10;
	int lastSunday = 6-day;
	int shortSE = -1;
	while(lastSunday + 7 < nDay) {
		shortSE = lastSunday;
		lastSunday += 7;
	}
	if(shortSE >= longS && shortSE < longE)
		return true;
	else
		return false;
}

void calcBlocks() {
	for( int y = 0 ; y < 2000 ; y++ )
		for( int m = 0 ; m < 12 ; m++ ) {
			int index = y*12 + m;
			int add = checkExtra(y,m);
			bool value = checkIntersect(firstDay[y][m], days[m]+add);
			sum[index+1] = sum[index] + value;
		}
}

void precalc() {
	calcFirstDay();
	calcBlocks();
}

int main() {
	precalc();
	scanf("%d",&T);
	for( int tc = 1 ; tc <= T ; tc++ ) {
		scanf("%d%d%d%d",&M1,&Y1,&M2,&Y2);
		M1--,Y1--,M2--,Y2--;
		LL index1 = (LL) Y1*12 + M1;
		LL index2 = (LL) Y2*12 + M2;
		LL group1 = index1 / PERIOD;
		LL group2 = index2 / PERIOD;
		LL pos1 = index1 % PERIOD;
		LL pos2 = index2 % PERIOD;
		LL ans = 0;
		if(group1 == group2)
			ans = sum[pos2+1] - sum[pos1];
		else {
			LL ng = group2 - group1 - 1;
			ans = ng * sum[PERIOD];
			ans += sum[pos2+1];
			ans += sum[PERIOD] - sum[pos1];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
