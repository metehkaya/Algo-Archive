class Solution {
public:
    int cnt5,cnt10,cnt20;
    bool lemonadeChange(vector<int>& ar) {
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ ) {
            if(ar[i] == 5)
                cnt5++;
            else if(ar[i] == 10) {
                if(!cnt5)
                    return false;
                cnt5--,cnt10++;
            }
            else {
                if(cnt5 > 0 && cnt10 > 0)
                    cnt5--,cnt10--,cnt20++;
                else if(cnt5 >= 3)
                    cnt5 -= 3 , cnt20++;
                else
                    return false;
            }
        }
        return true;
    }
};