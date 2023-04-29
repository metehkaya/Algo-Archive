class Solution {
public:
    bool rotateString(string A, string B) {
        int n = A.length();
        if(B.length() != n)
            return false;
        if(n == 0)
            return true;
        for( int i = 0 ; i < n ; i++ ) {
            string A1 = A.substr(0,i);
            string A2 = A.substr(i,n-i);
            string B1 = B.substr(n-i,i);
            string B2 = B.substr(0,n-i);
            if(A1.compare(B1) == 0 && A2.compare(B2) == 0)
                return true;
        }
        return false;
    }
};