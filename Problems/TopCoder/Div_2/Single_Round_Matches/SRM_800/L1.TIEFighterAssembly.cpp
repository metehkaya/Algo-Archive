#include <bits/stdc++.h>
using namespace std;

class TIEFighterAssembly {
	public:
    int assemble(string s) {
    	int a = 0 , b = 0 , c = 0;
    	int n = s.length();
    	for( int i = 0 ; i < n ; i++ )
    		if(s[i] == '|')
    			a++;
    		else if(s[i] == '-')
    			b++;
    		else if(s[i] == 'O')
    			c++;
    	int ans = n;
    	ans = min(ans,a/2);
    	ans = min(ans,b/2);
    	ans = min(ans,c);
    	return ans;
	}
};
