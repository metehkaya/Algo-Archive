class Solution {
public:
    int n;
    bool f(string& s , int i , int j) {
        while(i < j) {
            if(s[i] != s[j])
                return false;
            i++,j--;
        }
        return true;
    }
    bool check(string& a , string& b) {
        for( int i = 0 , j = n-1 ; i < j ; i++ , j-- )
            if(a[i] != b[j])
                return f(a,i,j) || f(b,i,j);
        return true;
    }
    bool checkPalindromeFormation(string a, string b) {
        n = a.size();
        return check(a,b) || check(b,a);
    }
};