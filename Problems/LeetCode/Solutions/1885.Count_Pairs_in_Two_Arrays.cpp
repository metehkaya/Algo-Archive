class Solution {
public:
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> v;
        for( int i = 0 ; i < n ; i++ )
            v.push_back(nums1[i]-nums2[i]);
        sort(v.begin(),v.end());
        long long ans = 0;
        for( int i = 0 , j = n-1 ; i < n-1 ; i++ ) {
            j = max(j,i+1);
            while(j > i and v[i]+v[j] > 0)
                j--;
            ans += n-j-1;
        }
        return ans;
    }
};
