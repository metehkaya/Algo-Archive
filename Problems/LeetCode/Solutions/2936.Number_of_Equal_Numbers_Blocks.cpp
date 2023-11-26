class BigArray {
    public:
    BigArray(vector<int> elements);
    int at(long long index);
    long long size();
};

class Solution {
public:
    int countBlocks(BigArray* nums) {
        int ans = 0;
        long long n = nums->size();
        for( long long idx = 0 , last ; idx < n ; idx = last+1 , ans++ ) {
            last = idx;
            long long l = idx+1 , r = n-1;
            int val = nums->at(idx);
            while(l <= r) {
                long long m = (l+r) >> 1;
                int val2 = nums->at(m);
                if(val == val2) {
                    last = m;
                    l = m+1;
                }
                else
                    r = m-1;
            }
        }
        return ans;
    }
};
