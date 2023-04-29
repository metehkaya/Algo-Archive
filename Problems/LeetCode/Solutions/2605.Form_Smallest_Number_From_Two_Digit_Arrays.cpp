class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        bool mark[2][10] = {false};
        for(int x : nums1)
            mark[0][x] = true;
        for(int x : nums2)
            mark[1][x] = true;
        for( int i = 1 ; i <= 99 ; i++ ) {
            int x = i/10;
            int y = i%10;
            if((mark[0][x] or mark[0][y]) and (mark[1][x] or mark[1][y]))
                return i;
        }
        return -1;
    }
};
