bool solution(int n) {
    string s = to_string(n);
    n = s.length();
    int sum = 0;
    for( int i = 0 ; i < n ; i++ )
        sum += (i < n/2) ? (s[i]-'0') : -(s[i]-'0');
    return (sum == 0);
}
