class Solution {
public:
    int lengthOfLIS(vector<int>& ar) {
        int n = ar.size() , len = 1;
        if(n == 0)
            return 0;
        vector<int> tail(n,INT_MAX);
        tail[0] = ar[0];
        for( int i = 1 ; i < n ; i++ ) {
            auto it = lower_bound(tail.begin(),tail.end(),ar[i]);
            if(it == tail.begin()+len)
                tail[len++] = ar[i];
            else
                *it = ar[i];
        }
        return len;
    }
};