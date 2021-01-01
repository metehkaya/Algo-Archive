class Solution {
public:
    int maxNonOverlapping(vector<int>& ar, int t) {
        map<int,int> idx;
        idx[0] = 0;
        int n = ar.size() , ans = 0 , sum = 0 , last = 0;
        for( int i = 1 ; i <= n ; i++ ) {
            sum += ar[i-1];
            auto it = idx.find(sum-t);
            if(it != idx.end() && it->second >= last)
                ans++ , last = i+1;
            idx[sum] = i+1;
        }
        return ans;
    }
};