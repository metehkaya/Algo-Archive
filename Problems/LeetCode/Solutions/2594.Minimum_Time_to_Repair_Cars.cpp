class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 1 , r = 1e14 , ans = 0;
        while(l <= r) {
            long long m = (l+r)/2 , sum = 0;
            for(int r : ranks)
                sum += sqrt(m/r);
            if(sum >= cars)
                ans = m , r = m-1;
            else
                l = m+1;
        }
        return ans;
    }
};
