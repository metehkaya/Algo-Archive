class Solution {
public:
    int minOperations(vector<int>& ar) {
        int N = ar.size();
        set<int> myset;
        for( int i = 0 ; i < N ; i++ )
            myset.insert(ar[i]);
        vector<int> arr(myset.begin(),myset.end());
        int n = arr.size() , ans = INT_MAX;
        for( int i = 0 , j = 0 ; i < n ; i++ ) {
            while(j < n && arr[j] <= arr[i]+N-1)
                j++;
            ans = min(ans,N-(j-i));
        }
        return ans;
    }
};