bool solution(string s) {
    string t = s;
    reverse(t.begin() , t.end());
    return s == t;
}
