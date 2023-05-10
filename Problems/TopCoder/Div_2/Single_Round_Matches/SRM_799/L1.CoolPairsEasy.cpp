#include <bits/stdc++.h>
using namespace std;

class CoolPairsEasy {
	public:
    int count(vector <string> a, vector <string> b) {
		int n = a.size() , ans = 0;
		for( int i = 0 ; i < n ; i++ )
			for( int j = 0 ; j < n ; j++ )
				if(i != j && b[i] == a[j])
					ans++;
		return ans;
	}
};
