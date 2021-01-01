class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& ar, vector<vector<int>>& q) {
        int n = ar.size() , m = q.size() , sum = 0;
        for( int i = 0 ; i < n ; i++ )
            if(abs(ar[i]) % 2 == 0)
                sum += ar[i];
        vector<int> ans;
        for( int i = 0 ; i < m ; i++ ) {
            int v = q[i][0] , id = q[i][1];
            int sub = 0 , add = 0;
            if(abs(ar[id]) % 2 == 0)
                sub = ar[id];
            ar[id] += v;
            if(abs(ar[id]) % 2 == 0)
                add = ar[id];
            sum += add-sub;
            ans.push_back(sum);
        }
        return ans;
    }
};