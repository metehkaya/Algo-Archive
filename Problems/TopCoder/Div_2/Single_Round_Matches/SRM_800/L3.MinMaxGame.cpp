#include <bits/stdc++.h>
using namespace std;

class MinMaxGame {
	public:
	int lastNumber(vector<int> ar) {
		int n = ar.size();
		if(n%2)
			return max(ar[0],ar[n-1]);
		return min(ar[0],ar[n-1]);
	}
};
