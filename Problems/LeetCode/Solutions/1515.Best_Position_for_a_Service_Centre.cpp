class Solution {
public:
    const int DIR[4] = {0,1,0,-1};
    double getCost(vector<vector<int>>& ar , double x , double y) {
        double sum = 0;
        for( int i = 0 ; i < ar.size() ; i++ ) {
            double cost = (x-ar[i][0])*(x-ar[i][0]) + (y-ar[i][1])*(y-ar[i][1]);
            sum += sqrt(cost);
        }
        return sum;
    }
    double getMinDistSum(vector<vector<int>>& ar) {
        int n = ar.size();
        double x = 50 , y = 50;
        double cost = getCost(ar,x,y);
        for( double step = 50 ; step >= 1e-6 ; ) {
            double tx,ty,tCost;
            bool better = false;
            for( int i = 0 ; i < 4 ; i++ ) {
                tx = x+step*DIR[i];
                ty = y+step*DIR[i^1];
                tCost = getCost(ar,tx,ty);
                if(tCost < cost) {
                    x = tx;
                    y = ty;
                    cost = tCost;
                    better = true;
                    break;
                }
            }
            if(!better)
                step /= 2;
        }
        return cost;
    }
};