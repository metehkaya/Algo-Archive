class Solution {
public:
    bool canAliceWin(int n) {
        bool alice = true , ans;
        for( int i = 10 ; i >= 1 ; i-- ) {
            if(n < i) {
                ans = !alice;
                break;
            }
            n -= i;
            alice = !alice;
        }
        return ans;
    }
};