#include <bits/stdc++.h>
using namespace std;

class PlanningTrips {
	public:
    int find(int a, vector <int> v) {
		int n = v.size();
		map<int,int> mp1;
		for( int i = 0 ; i < n ; i++ )
			mp1[v[i]]++;
		bool ok = true;
		map<int,int>::iterator it;
		do {
			ok = false;
			map<int,int> mp2;
			for( it = mp1.begin() ; it != mp1.end() ; it++ ) {
				int x = it->first;
				int y = it->second;
				if(y >= a)
					ok = true;
				for( int i = 0 ; y ; i++ ) {
					int add = y%a;
					if(add)
						mp2[x+i] += add;
					y /= a;
				}
			}
			mp1 = mp2;
		} while(ok);
		n = mp1.size();
		map<int,int>::reverse_iterator rit = mp1.rbegin();
		int ans = rit->first;
		if(n > 1 || rit->second > 1)
			ans++;
		return ans;
	}
};
