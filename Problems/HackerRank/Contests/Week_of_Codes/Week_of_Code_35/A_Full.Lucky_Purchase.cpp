#include <bits/stdc++.h>
using namespace std;

int n;
int cost,ansCost;
string word,ansWord;

int getBook() {
	cin >> word >> cost;
	int c = cost , c4 = 0 , c7 = 0;
	while(c) {
		if(c % 10 != 4 && c % 10 != 7)
			return -1;
		if(c % 10 == 4)
			c4++;
		else
			c7++;
		c /= 10;
	}
	if(c4 != c7)
		return -1;
	return cost;
}

int main() {
	ansCost = -1;
	scanf("%d",&n);
	for( int i = 0 ; i < n ; i++ ) {
		cost = getBook();
		if(cost == -1)
			continue;
		if(ansCost == -1 || cost < ansCost) {
			ansCost = cost;
			ansWord = word;
		}
	}
	if(ansCost == -1)
		puts("-1");
	else
		cout << ansWord << endl;
	return 0;
}
