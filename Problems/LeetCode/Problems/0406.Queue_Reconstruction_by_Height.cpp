class Solution {
public:
    static bool comp(vector<int>& a , vector<int>& b) {
        if(a[1] != b[1])
            return a[1] < b[1];
        return a[0] < b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& ar) {
        int n = ar.size();
        sort( ar.begin() , ar.end() , comp );
        vector<vector<int>> ans;
        for( int i = 0 ; i < n ; i++ ) {
            int index , cnt = 0;
            for( index = 0 ; index < i ; index++ ) {
                if( ar[i][0] <= ans[index][0] )
                    cnt++;
                if(cnt > ar[i][1])
                    break;
            }
            ans.resize(i+1);
            for( int j = i ; j > index ; j-- )
                ans[j] = ans[j-1];
            ans[index] = ar[i];
        }
        return ans;
    }
};