class Solution {
public:
    int subarraySum(vector<int>& ar, int k) {
        int ans = 0;
        int n = ar.size();
        unordered_map<int,int> hashh;
        unordered_map<int,int>::iterator iter;
        hashh[0] = 1;
        for( int i = 0 , sum = 0 ; i < n ; i++ ) {
            sum += ar[i];
            iter = hashh.find(sum-k);
            ans += hashh[sum-k];
            hashh[sum]++;
        }
        return ans;
    }
};