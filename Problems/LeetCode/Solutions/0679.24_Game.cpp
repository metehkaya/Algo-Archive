class Solution {
public:
    const double eps = 1e-6;
    bool checkZero(double x) {
        return abs(x) <= eps;
    }
    vector<double> find_add(double& x , double& y) {
        vector<double> add({x+y, x*y, x-y, y-x});
        if(!checkZero(x))
            add.push_back(y/x);
        if(!checkZero(y))
            add.push_back(x/y);
        return add;
    }
    bool solve(vector<double>& v) {
        int n = v.size();
        if(n == 1)
            return checkZero(v[0]-24);
        for( int i = 0 ; i < n ; i++ )
            for( int j = i+1 ; j < n ; j++ ) {
                vector<double> new_v;
                for( int k = 0 ; k < n ; k++ )
                    if(k != i and k != j)
                        new_v.push_back(v[k]);
                vector<double> add = find_add(v[i], v[j]);
                for(double x : add) {
                    new_v.push_back(x);
                    if(solve(new_v))
                        return true;
                    new_v.pop_back();
                }
            }
        return false;
    }
    bool judgePoint24(vector<int>& cards) {
        vector<double> v(cards.begin(), cards.end());
        return solve(v);
    }
};
