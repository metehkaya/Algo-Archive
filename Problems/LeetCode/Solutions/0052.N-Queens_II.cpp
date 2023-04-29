class Solution {
public:
    int n;
    int f(int row , int maskcol , int masksum , int maskdiff) {
        if(row == n)
            return 1;
        int ans = 0;
        for( int i = 0 ; i < n ; i++ ) {
            int m1 = i;
            int m2 = row+i;
            int m3 = row-i+(n-1);
            m1 = (1<<m1);
            m2 = (1<<m2);
            m3 = (1<<m3);
            if((maskcol & m1) == 0)
                if((masksum & m2) == 0)
                    if((maskdiff & m3) == 0)
                        ans += f(row+1,maskcol+m1,masksum+m2,maskdiff+m3);
        }
        return ans;
    }
    int totalNQueens(int n) {
        this->n = n;
        return f(0,0,0,0);
    }
};