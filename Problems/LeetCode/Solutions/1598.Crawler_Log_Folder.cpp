class Solution {
public:
    int minOperations(vector<string>& ar) {
        int n = ar.size() , ans = 0;
        for( int i = 0 ; i < n ; i++ )
            if(ar[i] == "../")
                ans = max(ans-1,0);
            else if(ar[i][0] != '.')
                ans++;
        return ans;
    }
};