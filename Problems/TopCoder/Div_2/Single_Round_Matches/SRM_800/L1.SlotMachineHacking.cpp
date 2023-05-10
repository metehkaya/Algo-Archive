#include <bits/stdc++.h>
#define pb push_back
using namespace std;

class SlotMachineHacking {
	public:
    int win(vector<string> ar, vector<int> steps) {
    	int n = ar.size();
    	vector<int> len;
    	vector<int> idx;
    	for( int i = 0 ; i < n ; i++ ) {
    		len.pb(ar[i].length());
    		steps[i] %= len[i];
    		for( int j = 0 ; j < len[i] ; j++ )
    			if(ar[i][j] == 'c')
    				idx.pb(j);
		}
		int s = 10000000;
		for( int t = 1 ; t <= s ; t++ ) {
			bool ok = true;
			for( int i = 0 ; i < n ; i++ ) {
				int k = t*steps[i] % len[i];
				if(k != idx[i])
					ok = false;
			}
			if(ok)
				return t-1;
		}
    	return -1;
	}
};
