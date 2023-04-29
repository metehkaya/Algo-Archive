typedef long long LL;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& ar) {
        int n = ar.size();
        LL total1 = n*(n+1)/2;
        LL total2 = (LL)n*(n+1)*(2*n+1)/6;
        LL sum1 = 0 , sum2 = 0;
        for( int i = 0 ; i < n ; i++ ) {
            sum1 += ar[i];
            sum2 += ar[i]*ar[i];
        }
        LL diff1 = sum1 - total1;
        LL diff2 = sum2 - total2;
        LL plus = diff2 / diff1;
        LL a = (plus + diff1) / 2;
        LL b = plus - a;
        vector<int> ans;
        ans.push_back(a);
        ans.push_back(b);
        return ans;
    }
};