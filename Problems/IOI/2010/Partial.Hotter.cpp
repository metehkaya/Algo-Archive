#include <bits/stdc++.h>
#include "grader.h"
using namespace std;

int l,r,mid;
int last,guess,ans;

void guessL() {
	guess = Guess(l);
	last = l;
	if(guess == 0) {
		ans = mid;
		return;
	}
	if((l+r)%2 == 0) {
		if(guess == 1)
			r = mid-1;
		else
			l = mid+1;
	}
	else {
		if(guess == 1)
			r = mid;
		else
			l = mid+1;
	}
}

void guessR() {
	guess = Guess(r);
	last = r;
	if(guess == 0) {
		ans = mid;
		return;
	}
	if((l+r)%2 == 0) {
		if(guess == -1)
			r = mid-1;
		else
			l = mid+1;
	}
	else {
		if(guess == -1)
			r = mid;
		else
			l = mid+1;
	}
}

int HC(int n) {
	srand(time(NULL));
	l = 1 , r = n;
	ans = -1 , last = -1 , guess = -1;
	while(l < r && ans == -1) {
		mid = (l+r) >> 1;
		if(guess == 1) {
			if(last == l)
				guessR();
			else
				guessL();
		}
		else {
			if(rand()%2 == 0) {
				Guess(l);
				guessR();
			}
			else {
				Guess(r);
				guessL();
			}
		}
	}
	return (ans == -1) ? l : ans;
}
