class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int min1 = INT_MAX , min2 = INT_MAX;
        for(int x : prices) {
            if(x <= min1) {
                min2 = min1;
                min1 = x;
            }
            else if(x <= min2)
                min2 = x;
        }
        return min1+min2 <= money ? money-(min1+min2) : money;
    }
};
