class Solution {
public:
    const double eps = 1e-6;
    double equalizeWater(vector<int>& v, int loss) {
        sort(v.begin(),v.end());
        double l = v.front() , r = v.back();
        double ans = l , rate = (100-loss) / 100.0;
        while(r-l > eps) {
            double m = (l+r)/2;
            double more = 0 , less = 0;
            for(int x : v)
                if(x >= m)
                    more += x-m;
                else
                    less += m-x;
            if(more*rate >= less)
                ans = m , l = m;
            else
                r = m;
        }
        return ans;
    }
};
