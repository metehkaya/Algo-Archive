class Solution {
public:
    int minCostSetTime(int startAt, int moveCost, int pushCost, int target) {
        int ar[4];
        int ans = INT_MAX;
        for( ar[0] = 0 ; ar[0] < 10 ; ar[0]++ )
            for( ar[1] = 0 ; ar[1] < 10 ; ar[1]++ )
                for( ar[2] = 0 ; ar[2] < 10 ; ar[2]++ )
                    for( ar[3] = 0 ; ar[3] < 10 ; ar[3]++ ) {
                        int h = 10*ar[0]+ar[1];
                        int m = 10*ar[2]+ar[3];
                        if(60*h+m != target)
                            continue;
                        int cost = 0 , idx = 0;
                        while(idx < 4 && ar[idx] == 0)
                            idx++;
                        int curr = startAt;
                        while(idx < 4) {
                            if(curr != ar[idx]) {
                                cost += moveCost;
                                curr = ar[idx];
                            }
                            cost += pushCost;
                            idx++;
                        }
                        ans = min(ans,cost);
                    }
        return ans;
    }
};
