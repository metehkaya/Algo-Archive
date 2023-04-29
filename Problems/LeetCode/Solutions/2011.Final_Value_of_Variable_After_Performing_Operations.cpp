class Solution {
public:
    int finalValueAfterOperations(vector<string>& ar) {
        int n = ar.size() , ans = 0;
        for( int i = 0 ; i < n ; i++ )
            if(ar[i][0] == '+' || ar[i][2] == '+')
                ans++;
            else
                ans--;
        return ans;
    }
};