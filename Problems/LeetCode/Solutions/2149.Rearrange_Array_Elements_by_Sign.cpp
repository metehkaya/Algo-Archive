class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos,neg;
        for(int x : nums) {
            if(x > 0)
                pos.push_back(x);
            else
                neg.push_back(x);
        }
        int n = pos.size();
        vector<int> ans(2*n);
        for( int i = 0 ; i < n ; i++ )
            ans[2*i] = pos[i] , ans[2*i+1] = neg[i];
        return ans;
    }
};
