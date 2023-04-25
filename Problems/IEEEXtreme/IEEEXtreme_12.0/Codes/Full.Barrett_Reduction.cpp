// Teammate : Osman Orhan Uysal

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int a, b;
    cin >> a >> b;
    b = 1ll << b;
    if( b % a )
    	cout << b/a+1 << endl;
    else
    	cout << b/a << endl;
    return 0;
}
