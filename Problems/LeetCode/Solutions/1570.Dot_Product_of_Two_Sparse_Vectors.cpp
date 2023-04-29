class SparseVector {
public:
    vector<vector<int>> v;
    SparseVector(vector<int> &nums) {
        int n = nums.size();
        for( int i = 0 ; i < n ; i++ )
            if(nums[i])
                v.push_back({i,nums[i]});
    }
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int ans = 0 , i = 0 , j = 0;
        int n = v.size() , m = vec.v.size();
        while(i < n and j < m) {
            if(v[i][0] < vec.v[j][0])
                i++;
            else if(v[i][0] > vec.v[j][0])
                j++;
            else
                ans += v[i++][1] * vec.v[j++][1];
        }
        return ans;
    }
};
