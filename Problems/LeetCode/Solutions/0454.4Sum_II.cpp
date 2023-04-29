class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int n = A.size();
        map<int,int> mp;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < n ; j++ )
                mp[A[i]+B[j]]++;
        int ans = 0;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < n ; j++ ) {
                int sum = -(C[i]+D[j]);
                if(mp.find(sum) != mp.end())
                    ans += mp[sum];
            }
        return ans;
    }
};