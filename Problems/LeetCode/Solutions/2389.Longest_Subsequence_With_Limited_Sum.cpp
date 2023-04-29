class Solution {
public:
    vector<int> answerQueries(vector<int>& ar, vector<int>& queries) {
        vector<int> ans;
        int n = ar.size() , m = queries.size();
        sort(ar.begin(),ar.end());
        for( int i = 0 ; i < m ; i++ ) {
            int res = 0 , sum = 0;
            for( int j = 0 ; j < n ; j++ ) {
                sum += ar[j];
                if(sum <= queries[i])
                    res = j+1;
                else
                    break;
            }
            ans.push_back(res);
        }
        return ans;
    }
};
