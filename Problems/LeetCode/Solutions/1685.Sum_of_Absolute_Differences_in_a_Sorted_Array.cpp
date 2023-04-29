class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& ar) {
        int total = 0;
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ )
            total += ar[i];
        vector<int> ans;
        for( int i = 0 , sum = 0 ; i < n ; sum += ar[i++] ) {
            int add = i*ar[i] - sum;
            add += (total-ar[i]-sum) - (n-1-i)*ar[i];
            ans.push_back(add);
        }
        return ans;
    }
};