#include <algorithm>
#include <stdio.h>
#include <string>
using namespace std;

const int LOWER = 100;
const int UPPER = 999;

int main() {
	int ans = 0;
	for( int i = LOWER ; i <= UPPER ; i++ )
		for( int j = LOWER ; j <= UPPER ; j++ ) {
			int mult = i*j;
			string s = to_string(mult);
			bool mark = true;
			int len = s.length();
			for( int k = 0 ; k < len/2 ; k++ )
				if(s[k] != s[len-1-k])
					mark = false;
			if(mark)
				ans = max(ans,mult);
		}
	printf("%d\n",ans);
	return 0;
}

