class Solution {
public:
    int lis(vector<int>& v) {
        vector<int> dp;
        for(int x : v) {
            vector<int>::iterator it = upper_bound(dp.begin(),dp.end(),x);
            if(it == dp.end())
                dp.push_back(x);
            else
                *it = x;
        }
        return (int) dp.size();
    }
    int kIncreasing(vector<int>& ar, int k) {
        int n = ar.size() , sum = 0;
        for( int i = 0 ; i < k ; i++ ) {
            vector<int> v;
            for( int j = i ; j < n ; j += k )
                v.push_back(ar[j]);
            sum += lis(v);
        }
        return n-sum;
    }
};
