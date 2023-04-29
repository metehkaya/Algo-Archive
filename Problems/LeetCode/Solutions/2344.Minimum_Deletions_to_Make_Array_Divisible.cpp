class Solution {
public:
    int gcd(int x , int y) {
        if(!y)
            return x;
        return gcd(y,x%y);
    }
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int g = numsDivide[0];
        for( int i = 1 ; i < numsDivide.size() ; i++ )
            g = gcd(g,numsDivide[i]);
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for( int i = 0 ; i < n ; i++ )
            if(g % nums[i] == 0)
                return i;
        return -1;
    }
};
