class Solution {
public:
    int findKthPositive(vector<int>& ar, int k) {
        int n = ar.size() , i = 0 , num = 0 , ans = -1;
        while(k && i < n) {
            num++;
            if(ar[i] != num)
                ans = num , k--;
            else
                i++;
        }
        ans = num + k;
        return ans;
    }
};