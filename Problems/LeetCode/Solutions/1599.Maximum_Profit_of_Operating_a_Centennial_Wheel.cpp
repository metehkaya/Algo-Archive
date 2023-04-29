class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int n = customers.size();
        int profit = 0 , rotations = 0 , rem = 0;
        int maxProfit = 0 , minRotations = -1;
        for( int i = 0 ; i < n || rem > 0 ; i++ ) {
            if(i < n)
                rem += customers[i];
            int add = min(rem,4);
            rem -= add;
            profit += add*boardingCost - runningCost;
            rotations++;
            if(profit > maxProfit)
                maxProfit = profit , minRotations = rotations;
        }
        return minRotations;
    }
};
