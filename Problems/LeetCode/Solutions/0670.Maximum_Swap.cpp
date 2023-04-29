class Solution {
public:
    vector<int> v;
    double pwr[9] = {1e0,1e1,1e2,1e3,1e4,1e5,1e6,1e7,1e8};
    void f(int x) {
        while(x) {
            v.push_back(x%10);
            x /= 10;
        }
    }
    int maximumSwap(int num) {
        if(num == 0)
            return 0;
        f(num);
        int ans = num;
        int sz = v.size();
        for( int i = 0 ; i < sz ; i++ )
            for( int j = i+1 ; j < sz ; j++ )
                if(v[i] > v[j]) {
                    int val = num;
                    val -= pwr[i] * v[i] + pwr[j] * v[j];
                    val += pwr[i] * v[j] + pwr[j] * v[i];
                    ans = max(ans,val);
                }
        return ans;
    }
};