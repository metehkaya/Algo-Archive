class Solution {
public:
    int maxNumberOfApples(vector<int>& ar) {
        int n = ar.size() , sum = 0 , ans = 0;
        sort(ar.begin(),ar.end());
        while(ans < n && sum+ar[ans] <= 5000)
            sum += ar[ans++];
        return ans;
    }
};