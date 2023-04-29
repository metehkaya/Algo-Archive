class Solution {
public:
    int dietPlanPerformance(vector<int>& arr, int k, int lower, int upper) {
        int n = arr.size();
        int sum = 0, ans = 0;
        for( int i = 0 ; i < k ; i++ )
            sum += arr[i];
        if(sum < lower)
            ans--;
        else if(sum > upper)
            ans++;
        for( int i = 1 ; i <= n-k ; i++ ) {
            sum -= arr[i-1];
            sum += arr[i+k-1];
            if(sum < lower)
                ans--;
            else if(sum > upper)
                ans++;
        }
        return ans;
    }
};