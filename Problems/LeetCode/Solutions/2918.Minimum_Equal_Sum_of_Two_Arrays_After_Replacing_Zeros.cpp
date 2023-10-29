class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0 , sum2 = 0;
        bool zero1 = false , zero2 = false;
        for(int x : nums1)
            if(x)
                sum1 += x;
            else
                sum1++ , zero1 = true;
        for(int x : nums2)
            if(x)
                sum2 += x;
            else
                sum2++ , zero2 = true;
        if(sum1 < sum2 and !zero1)
            return -1;
        else if(sum2 < sum1 and !zero2)
            return -1;
        return max(sum1,sum2);
    }
};
