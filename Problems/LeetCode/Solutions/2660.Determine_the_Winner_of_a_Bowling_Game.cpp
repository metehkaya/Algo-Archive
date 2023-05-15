class Solution {
public:
    int isWinner(vector<int>& p1, vector<int>& p2) {
        int n = p1.size() , diff = 0;
        for( int i = 0 ; i < n ; i++ ) {
            diff += p1[i];
            if((i >= 1 and p1[i-1] == 10) or (i >= 2 and p1[i-2] == 10))
                diff += p1[i];
        }
        for( int i = 0 ; i < n ; i++ ) {
            diff -= p2[i];
            if((i >= 1 and p2[i-1] == 10) or (i >= 2 and p2[i-2] == 10))
                diff -= p2[i];
        }
        if(diff > 0)
            return 1;
        else if(diff < 0)
            return 2;
        else
            return 0;
    }
};
