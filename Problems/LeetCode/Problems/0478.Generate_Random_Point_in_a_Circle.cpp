class Solution {
public:
    double r,xc,yc;
    Solution(double radius, double x_center, double y_center) {
        srand(time(NULL));
        r = radius;
        xc = x_center;
        yc = y_center;
    }
    bool inCircle(double x , double y) {
        return (x-xc)*(x-xc)+(y-yc)*(y-yc) <= r*r;
    }
    vector<double> randPoint() {
        double x,y;
        do {
            x = (double) rand() / RAND_MAX * 2*r + xc - r;
            y = (double) rand() / RAND_MAX * 2*r + yc - r;
        }while(!inCircle(x,y));
        vector<double> ans;
        ans.push_back(x);
        ans.push_back(y);
        return ans;
    }
};