class Solution {
public:
    int getMinSwaps(string num, int k) {
        string target = num;
        int n = num.length();
        for( int i = 0 ; i < k ; i++ )
            next_permutation(target.begin(), target.end());
        int ans = 0;
        for( int i = 0 ; i < n ; i++ )
            if(num[i] != target[i]) {
                int j = i;
                while(num[j] != target[i])
                    j++;
                ans += j-i;
                while(j > i) {
                    swap(num[j],num[j-1]);
                    j--;
                }
            }
        return ans;
    }
};