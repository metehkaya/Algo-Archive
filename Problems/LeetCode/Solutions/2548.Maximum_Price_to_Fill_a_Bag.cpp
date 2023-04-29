class Solution {
public:
    double maxPrice(vector<vector<int>>& v, int cap) {
        sort(v.begin() , v.end() , [&](auto& a , auto& b) {
            return a[0]*b[1] > a[1]*b[0];
        });
        double ans = 0;
        for(auto& item : v) {
            int used = min(cap,item[1]);
            double add = item[0] * (double) used / item[1];
            ans += add;
            cap -= used;
            if(cap == 0)
                break;
        }
        return cap == 0 ? ans : -1;
    }
};
